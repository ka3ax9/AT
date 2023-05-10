#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_SIZE 100

void readMatrix(int matrix[MAX_SIZE][MAX_SIZE], int size);
void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int size);
void replaceRowsWithColumns(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int size);

int main() {
    int size;
    int matrixA[MAX_SIZE][MAX_SIZE];
    int matrixB[MAX_SIZE][MAX_SIZE];

    printf("Введіть розмірність матриць: ");
    scanf("%d", &size);

    printf("Введіть елементи матриці A:\n");
    readMatrix(matrixA, size);

    printf("Введіть елементи матриці B:\n");
    readMatrix(matrixB, size);

    printf("\nПочаткова матриця A:\n");
    printMatrix(matrixA, size);

    printf("\nМатриця B:\n");
    printMatrix(matrixB, size);

    replaceRowsWithColumns(matrixA, matrixB, size);

    printf("\nМатриця A замінена відповідно до вимог:\n");
    printMatrix(matrixA, size);

    return 0;
}

void readMatrix(int matrix[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("Елемент [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void replaceRowsWithColumns(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        if (i % 2 != 0) {
            for (int j = 0; j < size; j++) {
                matrixA[i][j] = matrixB[j][i];
            }
        }
    }
}
