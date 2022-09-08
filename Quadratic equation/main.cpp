#include "solve.hpp"
#include "io.hpp"
#include "test.hpp"

int main(int argc, const char *argv[]) {
    double a = NAN, b = NAN, c = NAN, x_1 = NAN, x_2 = NAN;
    NUM_ROOTS num_roots = ZERO;

    if (mode(argc, argv) == TEST_MODE) {
        test();
        return 0;
    }
    input(&a, &b, &c);
    num_roots = solve(a, b, c, &x_1, &x_2);
    output(x_1, x_2, num_roots);
}











