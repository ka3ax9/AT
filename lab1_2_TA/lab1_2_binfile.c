#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void createBinaryFile(const char* filename, int* numbers, int numNumbers) {
    FILE* file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Помилка відкриття файлу.\n");
        return;
    }

    fwrite(numbers, sizeof(int), numNumbers, file);

    fclose(file);
}

int main() {
    const char* filename = "numbers.bin";
    int numbers[] = { 11, 22, 33, 44, 55, 66, 77, 88, 99, 110, 121, 132 };
    int numNumbers = sizeof(numbers) / sizeof(numbers[0]);

    createBinaryFile(filename, numbers, numNumbers);

    printf("Бінарний файл успішно створений.\n");

    return 0;
}
