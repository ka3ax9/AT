#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void createFileWithMultiplesOfEleven(char* inputFileName, char* outputFileName) {
    FILE* inputFile = fopen(inputFileName, "rb");
    FILE* outputFile = fopen(outputFileName, "w");

    if (inputFile == NULL || outputFile == NULL) {
        printf("Помилка при відкритті файлу.\n");
        exit(1);
    }

    int number;
    while (fread(&number, sizeof(int), 1, inputFile) == 1) {
        if (number % 11 == 0) {
            fprintf(outputFile, "%d\n", number);
        }
    }

    fclose(inputFile);
    fclose(outputFile);
}

int main() {
    createFileWithMultiplesOfEleven("input.bin", "output.txt");
    return 0;
}
