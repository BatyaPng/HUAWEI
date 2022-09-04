#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void input(double *a, double *b, double *c);

void solve(double a, double b, double c, double *x_1, double *x_2,
           int *num_roots);

void output(double x_1, double x_2, int num_roots);

int main() {
  double a = 0, b = 0, c = 0, x_1 = 0, x_2 = 0;
  int num_roots = 0;

  input(&a, &b, &c);
}

void input(double *a, double *b, double *c) {
  printf("Enter coefficients\n");
  int input = scanf("%lf%lf%lf", a, b, c);

  while (input != 3) {
    printf("Wrong input. Repeat");
    input = scanf("%lf%lf%lf", a, b, c);
    while (getchar() != '\n') {
    }
  }
}

void solve(double a, double b, double c, double *x_1, double *x_2,
           int *num_roots) {
  if (a == 0 && b != 0) {
    *x_1 = -c / b;
    *num_roots = 11;
    return;
  } else {
    double D = b * b - 4 * a * c;

    if (D >= 0) {
      *x_1 = (-b + sqrt(D)) / (2 * a);

      if (D == 0) {
        *num_roots = 21;
        return;
      }

      *x_2 = (-b - sqrt(D)) / (2 * a);
      *num_roots = 22;
      return;
    }
  }
  return;
}

void output(double x_1, double x_2, int num_roots) {
  switch (num_roots) {
  case 22:
    printf("Two roots exist: x_1 = %lf; x_2 = %lf\n", x_1, x_2);
    return;
  case 21:
    printf("One root exist: x = %lf\n", x_1);
    return;
  case 11:
    printf("This is linear expression: x = %lf\n", x_1);
    return;
  defualt:
    printf("There is no roots\n");
    return;
  }
}
