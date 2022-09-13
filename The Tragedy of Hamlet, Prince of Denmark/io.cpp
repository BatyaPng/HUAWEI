#include "io.hpp"

void input(FILE *fp) {
    fp = fopen("text.txt", "r");

    if (fp == NULL) {
        perror("fopen() failed");
        return;
    }
}