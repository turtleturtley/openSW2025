double mypow(double a, double b) {
    double result = 1.0;
    int exp = (int)b;

    for (int i = 0; i < exp; i++) {
        result *= a;
    }
    return result;
}
