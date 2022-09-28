#include "sort.hpp"

struct line *get_lines(const text text) {
    if (text.buffer == NULL) {
        perror("text.buffer null pointer");
        return NULL;
    }

    size_t cnt_lines = get_count_lines(text);

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

void sort_and_write(const text text, FILE *fp) {
    if (text.buffer == NULL) {
        perror("text.buffer null pointer");
        return;
    }

    fp = fopen("result.txt", "w");

    line *lines_p = get_lines(text);

    qsort(lines_p, text.n_lines, sizeof(struct line), cmp_by_fc);
    output(fp, lines_p, text);

    qsort(lines_p, text.n_lines, sizeof(struct line), cmp_by_lc);
    output(fp, lines_p, text);

    size_t result = fwrite(text.buffer, sizeof(char), text.len - 1, fp);
    if (result != text.len - 1) {
        perror("fwrite() failed");
        return;
    }

    destructor(text.buffer, lines_p);

    fclose(fp);
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

void swap(void *arr[], size_t i, size_t j, size_t size_elem) {
    if (arr == NULL) {
        perror("null poiner arr[] passed");
        return;
    }

    void *tmp = calloc(1, size_elem);
    memcpy(tmp ,((*(char **) arr) + i * size_elem), size_elem);

    memcpy(((*(char **) arr) + i * size_elem), ((*(char **) arr) + j * size_elem), size_elem);
    memcpy(((*(char **) arr) + j * size_elem), tmp, size_elem);

    free(tmp);
}

void my_qsort(void *arr, size_t count, size_t size_elem, int (*comp)(const void *, const void *)) {
    if (arr == NULL) {
        perror("null pointer arr passed");
        return;
    }

    if (size_elem == sizeof(char)) {
        char last_elem = ((char *) arr)[count - 1];

        while (last_elem == 0) {
            count--;
            last_elem = ((char *) arr)[count - 1];
        }
    }

    if (count == 1) {
        return;
    }

    size_t left = 0;
    size_t middle = count / 2;
    size_t right = count - 1;

    void *left_elem = NULL;
    void *middle_elem = NULL;
    void *right_elem = NULL;

    do {
        left_elem = (void *) ((char*) arr + (size_elem * left));
        middle_elem = (void *) ((char*) arr + (size_elem * middle));
        right_elem = (void *) ((char*) arr + (size_elem * right));

        while ((*comp)(left_elem, middle_elem) < 0) {
            left++;
            left_elem = (void *) ((char*) arr + (size_elem * left));
        }

        while ((*comp)(right_elem, middle_elem) > 0) {
            right--;
            right_elem = (void *) ((char*) arr + (size_elem * right));
        }

        if (left <= right) {
            swap(&arr, left, right, size_elem);

            left++;
            right--;
        }

    } while (left <= right);

    if (right > 0)
        my_qsort(arr, right + 1, size_elem, comp);
    if (left < count) {
        void *r_arr = (void *) ((char *) arr + size_elem * left); 
        my_qsort(r_arr, count - left, size_elem, comp);
    }
}