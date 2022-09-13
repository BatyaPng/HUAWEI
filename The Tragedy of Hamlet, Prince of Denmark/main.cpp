#include "io.hpp"

int main() {
    FILE *fp = NULL;

    input(fp);
    solve(fp);
    output(fp);

    return 0;
}