#include <stdio.h>

int add(int a, int b)        { return a + b; }
int subtract(int a, int b)   { return a - b; }
int multiply(int a, int b)   { return a * b; }
int divide(int a, int b)     { return b != 0 ? a / b : 0; }
int power(int a, int b) {
    int result = 1;
    for (int i = 0; i < b; i++)
        result *= a;
    return result;
}

int main() {
    system("chcp 65001");
    int (*operations[5])(int, int) = { add, subtract, multiply, divide, power };
    int a = 3, b = 5;
    printf("a = %d, b = %d\n", a, b);
    for (int i = 0; i < 5; i++) {
        int result = operations[i](a, b);
        printf("Результат операції %d: %d\n", i + 1, result);
    }

    return 0;
}