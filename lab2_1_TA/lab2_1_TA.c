#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Структура для зберігання даних про метали
struct Metal {
    char substance[50];          // Назва речовини
    int atomicNumber;            // Атомний номер
    float temperature;           // Температура в градусах Цельсія
    float viscosity;             // В'язкість у кг/м*сек
};

// Функція для порівняння двох металів за значеннями першого стовпця (substance)
int compareMetals(const void* a, const void* b) {
    struct Metal* metalA = (struct Metal*)a;
    struct Metal* metalB = (struct Metal*)b;
    return strcmp(metalA->substance, metalB->substance);
}

int main() {
    // Створення масиву структур Metal для зберігання даних
    struct Metal metals[] = {
        {"Алюміній", 13, 700, 2.90},
        {"Вісмут", 83, 304, 1.65},
        {"Свинець", 82, 441, 2.11}
    };

    int numMetals = sizeof(metals) / sizeof(metals[0]);

    // Сортування металів за значеннями першого стовпця (substance)
    qsort(metals, numMetals, sizeof(struct Metal), compareMetals);

    // Виведення заголовків таблиці
    printf("_______________________________________________________________________________________\n");
    printf("|В’язкість металів в рідкому стані                                                    |\n");
    printf("|-------------------------------------------------------------------------------------|\n");
    printf("|%-12s\t| %-15s \t| %-18s \t| %-20s\n", "Речовина", "Атомний номер", "Температура (град.С)", "В’язкість (кг/м*сек)|");
    printf("|-------------------------------------------------------------------------------------|\n");

    // Виведення даних з таблиці
    for (int i = 0; i < numMetals; i++) {
        printf("|%-12s \t| %-15d \t| %-18.0f \t| %-20.2f|\n", metals[i].substance, metals[i].atomicNumber, metals[i].temperature, metals[i].viscosity);
        printf("|-------------------------------------------------------------------------------------|\n");
    }

    // Виведення коментарів до таблиці
    printf("|Зауваження: подані дані для температури плавлення металів.                           |\n");
    printf("|_____________________________________________________________________________________|\n");

    return 0;
}
