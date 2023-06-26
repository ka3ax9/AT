#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>

int main() {
    FILE* file;
    char filename[] = "file.txt";
    char firstChar, secondChar;

    // Відкриття файлу
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Помилка відкриття файлу.\n");
        return 1;
    }

    // Зчитування перших двох символів з файлу
    firstChar = fgetc(file);
    secondChar = fgetc(file);

    // Перевірка, чи перші два символи є цифрами
    if (isdigit(firstChar) && isdigit(secondChar)) {
        int number = (firstChar - '0') * 10 + (secondChar - '0');

        // Перевірка, чи знайдене число є парним
        if (number % 2 == 0) {
            printf("Знайдене число %d є парним.\n", number);
        }
        else {
            printf("Знайдене число %d не є парним.\n", number);
        }
    }
    else {
        printf("Перші два символи не є цифрами.\n");
    }

    // Закриття файлу
    fclose(file);

    return 0;
}
