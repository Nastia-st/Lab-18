#include <stdio.h>
#include <math.h>
#define MAX 100

void input_array(double arr[], int size, char name) {
    for (int i = 0; i < size; i++) {
        printf("Введіть %c[%d]: ", name, i);
        scanf("%lf", &arr[i]);
    }
}

void process_array(double arr[], int size, double *sum, double *product, double *special_result,
                   char mode) {
    *sum = 0;
    *product = 1;
    *special_result = 0;

    for (int i = 0; i < size; i++) {
        *sum += arr[i];
        *product *= arr[i];

        switch (mode) {
            case 's': *special_result += arr[i] * sin(arr[i]); break;
            case 'c': *special_result += arr[i] * cos(arr[i]); break;
            case 't': *special_result += arr[i] * tan(arr[i]); break;
            case 'e': *special_result += arr[i] * exp(arr[i]); break;
            case 'k': *special_result += arr[i] * cos(arr[i]); break;
        }
    }
}

int main() {
    system("chcp 65001");
    int n, m;
    double x[MAX], y[MAX];

    printf("Введіть кількість елементів масиву x (n): ");
    scanf("%d", &n);
    input_array(x, n, 'x');
    printf("Введіть кількість елементів масиву y (m): ");
    scanf("%d", &m);
    input_array(y, m, 'y');

    double s_x, p_x, sum_x_sin, sum_x_cos, sum_x_tan;
    process_array(x, n, &s_x, &p_x, &sum_x_sin, 's');
    process_array(x, n, &s_x, &p_x, &sum_x_cos, 'c');
    process_array(x, n, &s_x, &p_x, &sum_x_tan, 't');
    double A = s_x * sum_x_sin;
    double B = p_x * sum_x_cos;
    double C = (s_x + p_x) * sum_x_tan;
    double s_y, p_y, sum_y_tan, sum_y_exp, sum_y_cos;
    process_array(y, m, &s_y, &p_y, &sum_y_tan, 't');
    process_array(y, m, &s_y, &p_y, &sum_y_exp, 'e');
    process_array(y, m, &s_y, &p_y, &sum_y_cos, 'k');

    double D = s_x * sum_y_tan;
    double E = p_x * sum_y_exp;
    double F = (s_x + p_x) * sum_y_cos;
    double gamma = (A + B * cos(C)) / (D + E * sin(F));

    printf("\nРезультат обчислення = %lf\n", gamma);
    return 0;
}
