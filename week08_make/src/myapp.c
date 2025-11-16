#include <stdio.h>
#include "basic_ops.h"

double calculate(char op, double a, double b) {
    if (op == '+') {
        return add(a, b);
    } else if (op == '-') {
        return sub(a, b);
    } else if (op == '*') {
        return mul(a, b);
    } else if (op == '/') {
        return div(a, b);
    } else {
        printf("Unsupported operation: %c\n", op);
        return 0;
    }
}

int main() {
    double a, b;
    char op;

    printf("Enter expression (e.g., 1 + 2): ");
    scanf("%lf %c %lf", &a, &op, &b);

    printf("Result = %.2f\n", calculate(op, a, b));
    return 0;
}
