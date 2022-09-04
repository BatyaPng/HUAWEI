#include <math.h>
#include <stdio.h>
#include <stdlib.h>

enum Num_roots { zero = 0, one_lin = 11, one_sqr = 21, two_sqr = 22 };

void input(double *a, double *b, double *c);

void solve(double a, double b, double c, double *x_1, double *x_2,
           enum Num_roots *num_roots);

void output(double x_1, double x_2, enum Num_roots num_roots);

void clean_buff();

int is_buff_empty();

int main() {
  double a = 0, b = 0, c = 0, x_1 = 0, x_2 = 0;
  enum Num_roots num_roots = zero;

  input(&a, &b, &c);
  solve(a, b, c, &x_1, &x_2, &num_roots);
  output(x_1, x_2, num_roots);
}

void input(double *a, double *b, double *c) {
  printf("Enter coefficients\n");
  int input = scanf("%lf%lf%lf", a, b, c);

  while (is_buff_empty() || input != 3) {
    clean_buff();
    printf("Wrong input. Repeat\n");
    input = scanf("%lf%lf%lf", a, b, c);
  }
}

void solve(double a, double b, double c, double *x_1, double *x_2,
           enum Num_roots *num_roots) {
  double eps = 0.001;

  if (a == 0 && b != 0) {
    *x_1 = -c / b;
    *num_roots = one_lin;
    return;
  } else if (a + b == 0)
    return;
  else {
    double D = b * b - 4 * a * c;

    if (D >= 0) {
      *x_1 = (-b + sqrt(D)) / (2 * a);

      if (fabs(D) >= eps) {
        *num_roots = one_sqr;
        return;
      }

      *x_2 = (-b - sqrt(D)) / (2 * a);
      *num_roots = two_sqr;
      return;
    }
  }
  return;
}

void output(double x_1, double x_2, enum Num_roots num_roots) {
  switch (num_roots) {
  case two_sqr:
    printf("Two roots exist: x_1 = %lf; x_2 = %lf\n", x_1, x_2);
    return;
  case one_sqr:
    printf("One root exist: x = %lf\n", x_1);
    return;
  case one_lin:
    printf("This is linear expression: x = %lf\n", x_1);
    return;
  default:
    printf("There is no roots\n");
    return;
  }
}

void clean_buff() {
  while (getchar() != '\n') {
  }
}

int is_buff_empty() {
  if (getchar() != '\n')
    return 1;
  return 0;
}