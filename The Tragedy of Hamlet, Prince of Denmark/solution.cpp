#include "solution.hpp"

void solve(line *text) {
    size_t cnt_lines = get_count_lines(*text);

    struct line *sub_linep = (struct line *) calloc(cnt_lines, sizeof(struct line));
    if(sub_linep == NULL) {
        perror("calloc() failed");
        return;
    }

    size_t n_str = 0;

    for(size_t i = 0; i < text -> len; i++) {
        size_t len = 0;
        char ch = text -> buffer[i];  

        if (isalpha(ch)) {
            sub_linep[n_str].buffer = &(text -> buffer[i]);

            while (((ch = text -> buffer[i]) != '\n') && ch != 0) {
                len++;
                i++;
            }
            sub_linep[n_str].len = len + 1;
            n_str++;
        }
    }

    for (size_t i = 0; i < cnt_lines; i++) {
        for (size_t j = 0; j < sub_linep[i].len; j++) {
            printf("%c", sub_linep[i].buffer[j]);
        }
    }
    
    qsort(sub_linep, cnt_lines, sizeof(struct line), line_cmp);

    for (size_t i = 0; i < cnt_lines; i++) {
        for (size_t j = 0; j < sub_linep[i].len; j++) {
            printf("%c", sub_linep[i].buffer[j]);
        }
    }

    free(text -> buffer);
    free(sub_linep);
}

int line_cmp(const void *str_1, const void *str_2) {
    const line *line_1 = (const line *) str_1;
    const line *line_2 = (const line *) str_2;

    size_t min_len = (size_t) min((int) line_1 -> len, (int) line_2 -> len);

    char ch_1 = 0;
    char ch_2 = 0;

    for (size_t i = 0; i < min_len; i++) {
        ch_1 = line_1 -> buffer[i];
        ch_2 = line_2 -> buffer[i];

        // printf("%c", ch_1);

        if (isalpha(ch_1) && isalpha(ch_2)) {
            return (int) ch_1 - (int) ch_2;
        }       
    }

    return 0;
}