#include "sort.hpp"

struct line *get_lines(const text text) {
    if (text.buffer == NULL) {
        perror("text.buffer null pointer");
        return NULL;
    }

    size_t cnt_lines = text.n_lines;

    struct line *lines_p = (struct line *) calloc(cnt_lines, sizeof(struct line));
    if (lines_p == NULL) {
        perror("calloc() failed");
        return NULL;
    }

    size_t n_str = 0;
    size_t len = 0;
    char ch = 0;

    for (size_t i = 0; i < text.len; i++) {
        len = 0;
        ch = text.buffer[i];  

        if (isalpha(ch)) {
            lines_p[n_str].buffer = &(text.buffer[i]);

            while (((ch = text.buffer[i]) != '\n') && (ch != 0)) {
                len++;
                i++;
            }

            lines_p[n_str].len = len + 1;
            n_str++;
        }
    }

    return lines_p;
}

int cmp_by_fc(const void *str_1, const void *str_2) {
    const line *line_1 = (const line *) str_1;
    const line *line_2 = (const line *) str_2;

    size_t min_len = (size_t) min((int) line_1 -> len, (int) line_2 -> len);

    char ch_1 = 0;
    char ch_2 = 0;

    for (size_t i = 0; i < min_len; i++) {
        ch_1 = line_1 -> buffer[i];
        ch_2 = line_2 -> buffer[i];

        if ((ch_1 != ch_2) && (isalpha(ch_1) && isalpha(ch_2))) {
            return (int) ch_1 - (int) ch_2;
        }       
    }

    return 0;
}

int cmp_by_lc(const void *str_1, const void *str_2) {
    const line *line_1 = (const line *) str_1;
    const line *line_2 = (const line *) str_2;

    int i_line1 = (int) line_1 -> len - 1;
    int i_line2 = (int) line_2 -> len - 1;

    char ch_1 = 0;
    char ch_2 = 0;

    while (i_line1 >= 0 && i_line2 >= 0) {
        ch_1 = line_1 -> buffer[i_line1];
        ch_2 = line_2 -> buffer[i_line2];

        if ((ch_1 != ch_2) && (isalpha(ch_1) && isalpha(ch_2))) {
            return (int) ch_1 - (int) ch_2;
        }

        i_line1--;
        i_line2--;
    }

    return 0;
}
