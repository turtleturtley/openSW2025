#include <stdio.h>
#include <string.h>
#include "../include/myops.h"

double calculate(char op, double a, double b)
{
    printf("Calculating.....\n");

    if (op == '+') return myadd(a, b);
    if (op == '-') return mysub(a, b);
    if (op == '*') return mymul(a, b);
    if (op == '/') return mydiv(a, b);
    if (op == '%') return mymod(a, b);   
    if (op == '^') return mypow(a, b);

    printf("Unsupported operator: %c\n", op);
    return 0.0;
}

int main(void)
{
    double a, b;
    char op;

    printf("~~~ Welcome to my calculator  ~~~\n\n");
    printf("Enter expression (e.g. 1 + 2): ");
    scanf("%lf %c %lf", &a, &op, &b);

    printf("Result = %.2lf\n", calculate(op, a, b));
    printf("~~~ Good bye. See you again ~~~\n\n");

    return 0;
}
