#include "io/io.hpp"

int main() {
    FILE *src_fp = NULL, *dst_fp = NULL;

    struct line *buffer = input(src_fp);
    if (buffer == NULL) {
        perror("input() failed");
        return -1;
    }

    solve(buffer);
    // output(dst_fp);

    free(buffer);

    return 0;
}