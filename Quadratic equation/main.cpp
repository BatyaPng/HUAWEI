#include "solve.hpp"
#include "io.hpp"

int main() {
    double a = 0, b = 0, c = 0, x_1 = 0, x_2 = 0;
    enum NUM_ROOTS num_roots = ZERO;

    input(&a, &b, &c);
    num_roots = solve(a, b, c, &x_1, &x_2);
    output(x_1, x_2, num_roots);
}











