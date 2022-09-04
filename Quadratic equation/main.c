#include <stdio.h>
#include <stdlib.h>

void input(double *a, double *b, double *c);

int main() {
  double a = 0, b = 0, c = 0, D = 0, x_1 = 0, x_2 = 0;

  input(&a, &b, &c);
}

void input(double *a, double *b, double *c) {
  printf("Enter coefficients\n");
  int input = scanf("%lf %lf %lf", a, b, c);
  while (input != 3) {
    printf("Wrong input. Repeat");
    input = scanf("%lf%lf%lf", a, b, c);
    while (getchar() != '\n') {
    }
  }
}