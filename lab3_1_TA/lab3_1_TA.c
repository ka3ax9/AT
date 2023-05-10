#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

double Sum(double numbers[], int n) {
    if (n == 0) {
        return 0;
    }
    return numbers[n - 1] + Sum(numbers, n - 1);
}

int main() {
    int n;
    printf("Введіть кількість чисел: ");
    scanf("%d", &n);

    double* numbers = (double*)malloc(n * sizeof(double));
    printf("Введіть %d чисел:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &numbers[i]);
    }

    double sum = Sum(numbers, n);
    printf("Сума: %.2lf\n", sum);

    free(numbers);  // Звільняємо пам'ять, виділену для масиву numbers

    return 0;
}

