#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void create_multiple_of_11_file(char* input_file, char* output_file) {
    FILE* input = fopen(input_file, "rb");
    if (input == NULL) {
        printf("Помилка: неможливо відкрити вхідний файл!\n");
        return;
    }

    FILE* output = fopen(output_file, "wb");
    if (output == NULL) {
        printf("Помилка: неможливо створити вихідний файл!\n");
        return;
    }

    int num;
    int count = 0; // Лічильник кратних чисел

    while (fread(&num, sizeof(int), 1, input)) {
        if (num % 11 == 0) {
            fwrite(&num, sizeof(int), 1, output);
            count++;
        }
    }

    fclose(input);
    fclose(output);

    printf("Файл успішно створено! Кількість кратних чисел: %d\n", count);
}

int main() {
    char input_file[] = "input.bin";
    char output_file[] = "output.bin";
    create_multiple_of_11_file(input_file, output_file);
    return 0;
}
