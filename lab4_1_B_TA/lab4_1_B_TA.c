#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n, i;
    int* arr;
    int sum = 0;
    int count = 0;
    float average;

    printf("Введіть розмір масиву: ");
    scanf("%d", &n);

    // Перевірка коректності введеного розміру масиву
    if (n <= 0) {
        printf("Некоректний розмір масиву.\n");
        return 1;
    }

    // Виділення пам'яті під масив
    arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Не вдалося виділити пам'ять.\n");
        return 1;
    }

    // Ініціалізація генератора псевдовипадкових чисел
    srand(time(NULL));

    // Заповнення масиву псевдовипадковими числами
    for (i = 0; i < n; i++) {
        arr[i] = rand() % 201 - 100; // Генеруємо число від -100 до 100
    }

    // Виведення елементів масиву
    printf("Елементи масиву:\n");
    for (i = 0; i < n; i++) {
        printf("a[%d] = %d\n", i, arr[i]);
    }

    // Обчислення середнього арифметичного парних елементів
    for (i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            sum += arr[i];
            count++;
        }
    }

    if (count > 0) {
        average = (float)sum / count;
        printf("Середнє арифметичне значення парних елементів: %.2f\n", average);
    }
    else {
        printf("У масиві немає парних елементів.\n");
    }

    // Звільнення пам'яті, виділеної під масив
    free(arr);

    return 0;
}
