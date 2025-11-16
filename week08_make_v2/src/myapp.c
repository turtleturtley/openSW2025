#include <stdio.h>
#include "basic_ops.h"
#include "advanced_ops.h"

double calculate(char op, double a, double b) {
    if (op == '+') return add(a, b);
    else if (op == '-') return sub(a, b);
    else if (op == '*') return mul(a, b);
    else if (op == '/') return div(a, b);
    else if (op == '%') return mymod(a, b);
    else if (op == '^') return mypow(a, b);
    else {
        printf("Unsupported operation: %c\n", op);
        return 0;
    }
}

int main() {
    double a, b;
    char op;
    printf("Enter expression (e.g., 7 % 3): ");
    scanf("%lf %c %lf", &a, &op, &b);
    printf("Result = %.2lf\n", calculate(op, a, b));
    return 0;
}
