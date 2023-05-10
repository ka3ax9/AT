#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fillMatrix(int** matrix, int size);
void printMatrix(int** matrix, int size);
void replaceRowsWithColumns(int** matrixA, int** matrixB, int size);

int main() {
    int size;
    int** matrixA;
    int** matrixB;

    printf("Введіть розмірність матриць: ");
    scanf("%d", &size);

    // Виділення пам'яті для матриць
    matrixA = (int**)malloc(size * sizeof(int*));
    matrixB = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        matrixA[i] = (int*)malloc(size * sizeof(int));
        matrixB[i] = (int*)malloc(size * sizeof(int));
    }

    // Заповнення матриць випадковими значеннями
    srand(time(NULL));
    fillMatrix(matrixA, size);
    fillMatrix(matrixB, size);

    printf("\nПочаткова матриця A:\n");
    printMatrix(matrixA, size);

    printf("\nМатриця B:\n");
    printMatrix(matrixB, size);

    replaceRowsWithColumns(matrixA, matrixB, size);

    printf("\nМатриця A замінена відповідно до вимог:\n");
    printMatrix(matrixA, size);

    // Звільнення пам'яті
    for (int i = 0; i < size; i++) {
        free(matrixA[i]);
        free(matrixB[i]);
    }
    free(matrixA);
    free(matrixB);

    return 0;
}

void fillMatrix(int** matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = rand() % 201 - 100; // Генерація числа від -100 до 100
        }
    }
}

void printMatrix(int** matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void replaceRowsWithColumns(int** matrixA, int** matrixB, int size) {
    for (int i = 0; i < size; i++) {
        if (i % 2 != 0) {
            for (int j = 0; j < size; j++) {
                matrixA[i][j] = matrixB[j][i];
            }
        }
    }
}
