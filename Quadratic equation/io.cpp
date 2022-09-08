#include "io.hpp"

void input(double *a, double *b, double *c) {
    assert(a != nullptr || b != nullptr || c != nullptr);

    printf("Enter coefficients\n");
    int input = scanf("%lf%lf%lf", a, b, c);

    while (is_buff_empty() || input != 3) {
        clean_buff();
        printf("Wrong input. Repeat\n");
        input = scanf("%lf%lf%lf", a, b, c);
    }
}

void output(const double x_1, const double x_2, const enum NUM_ROOTS num_roots) {
    switch (num_roots) {
    case ZERO:
        printf("There is no roots\n");
        return;
    case ONE_LIN:
        printf("This is linear equation: x = %lg\n", x_1);
        return;
    case ONE_SQR:
        printf("One root exists: x = %lg\n", x_1);
        return;
    case TWO_SQR:
        printf("Two roots exist: x_1 = %lg; x_2 = %lg\n", x_1, x_2);
        return;
    case INF:
        printf("Infinite number of roots\n");
        return;  
    default:
        printf("An error occurred while executing the program\n");
        abort();
    }
}