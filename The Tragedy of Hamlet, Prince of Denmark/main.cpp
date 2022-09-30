#include "io/io.hpp"

// #define STD_QSORT

int main() {
    FILE *src_fp = NULL, *dst_fp = NULL;

    text text = input(src_fp);
    if (text.buffer == NULL) {
        perror("input() failed");
        return 1;
    }
    
    #ifdef STD_QSORT
        dst_fp = fopen("result1.txt", "w");
    #else
        dst_fp = fopen("result2.txt", "w");
    #endif

    if (dst_fp == NULL) {
        perror("fopen() failed");
        return 1;
    }

    line *lines_p = get_lines(text);

    #ifdef STD_QSORT
        qsort(lines_p, text.n_lines, sizeof(struct line), cmp_by_fc);
    #else
        my_qsort(lines_p, text.n_lines, sizeof(struct line), cmp_by_fc);
    #endif
    output(dst_fp, lines_p, text, AFTER_SORTING); 

    #ifdef STD_QSORT
        qsort(lines_p, text.n_lines, sizeof(struct line), cmp_by_lc);
    #else
        my_qsort(lines_p, text.n_lines, sizeof(struct line), cmp_by_lc);
    #endif
    output(dst_fp, lines_p, text, AFTER_SORTING);

    output(dst_fp, lines_p, text, BEFORE_SORTING);

    destructor(text.buffer, lines_p);
    fclose(dst_fp);
        
    return 0;
}