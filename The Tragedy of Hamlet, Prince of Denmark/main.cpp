#include "io/io.hpp"

int main() {
    FILE *src_fp = NULL, *dst_fp = NULL;

    text text = input(src_fp);
    if (text.buffer == NULL) {
        perror("input() failed");
        return 1;
    }

    sort_and_write(text, dst_fp);
    
    return 0;
}