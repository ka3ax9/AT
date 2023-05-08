#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, ".65001"); // Встановлюємо кодування UTF-8

    FILE* file;
    char symbol;
    int first_digit, second_digit;

    // Відкриття файлу для читання
    fopen_s(&file, "file.txt", "r");

    // Перевірка, чи файл вдало відкрито
    if (file == NULL) {
        printf("Помилка при відкритті файлу\n");
        exit(1);
    }

    // Читання першого символу
    symbol = fgetc(file);

    // Перевірка, чи перший символ є цифрою
    if (symbol >= '0' && symbol <= '9') {
        first_digit = symbol - '0';

        // Читання другого символу
        symbol = fgetc(file);

        // Перевірка, чи другий символ є цифрою
        if (symbol >= '0' && symbol <= '9') {
            second_digit = symbol - '0';

            // Перевірка, чи знайдене число є парним
            if ((first_digit * 10 + second_digit) % 2 == 0) {
                printf("Знайдене число є парним\n");
            }
            else {
                printf("Знайдене число є непарним\n");
            }
        }
        else {
            printf("Другий символ не є цифрою\n");
        }
    }
    else {
        printf("Перший символ не є цифрою\n");
    }

    // Закриття файлу
    fclose(file);

    return 0;
}
