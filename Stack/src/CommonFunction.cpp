#include "CommonFunction.hpp"

size_t HashFAQ6(void *data, size_t size) {
    size_t hash = 0;
    char *str = (char *) data;

    for (size_t i = 0; i < size; i++) {
        hash += (unsigned char) (str[i]);
        hash += hash << 10;
        hash ^= hash >> 6;
    }

    hash += hash << 3;
    hash ^= hash >> 11;
    hash += hash << 15;

    return hash;
}
