#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char name[50];
    int id;
    int marks[5];
    float average;
};

void swap(struct Student* a, struct Student* b) {
    struct Student temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(struct Student* students, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (students[j].average < students[j + 1].average) {
                swap(&students[j], &students[j + 1]);
            }
        }
    }
}

void printTable(struct Student* students, int n) {
    printf("----------------------------------------------------------\n");
    printf("| %-20s \t| %-10s \t| %-10s\n", "Прізвище та ім'я", "№ зал. кн.", "Середня оцінка |");
    printf("----------------------------------------------------------\n");

    for (int i = 0; i < n; i++) {
        printf("| %-20s \t| %-10d \t| %-10.2f \t |\n", students[i].name, students[i].id, students[i].average);
    }

    printf("----------------------------------------------------------\n");
}

int main() {
    int n;
    printf("Введіть кількість студентів: ");
    scanf("%d", &n);

    struct Student* students = (struct Student*)malloc(n * sizeof(struct Student));

    for (int i = 0; i < n; i++) {
        printf("Студент %d:\n", i + 1);
        printf("Прізвище та ім'я: ");
        scanf(" %[^\n]s", students[i].name);
        printf("№ зал. кн.: ");
        scanf("%d", &students[i].id);
        printf("Оцінки (п'ять чисел через пробіл): ");
        for (int j = 0; j < 5; j++) {
            scanf("%d", &students[i].marks[j]);
        }

        // Обчислення середньої оцінки
        int sum = 0;
        for (int j = 0; j < 5; j++) {
            sum += students[i].marks[j];
        }
        students[i].average = (float)sum / 5;
    }

    bubbleSort(students, n);

    printf("\nТаблиця успішності студентів:\n");
    printTable(students, n);

    // Обчислення відсотку студентів з оцінками "добре" та "відмінно"

    int goodCount = 0;
    int excellentCount = 0;

    for (int i = 0; i < n; i++) {
        if (students[i].average >= 4.5 && students[i].average < 5.0) {
            goodCount++;
        }
        else if (students[i].average >= 5.0) {
            excellentCount++;
        }
    }

    float goodPercentage = (float)goodCount / n * 100;
    float excellentPercentage = (float)excellentCount / n * 100;

    printf("\nВідсоток студентів з оцінкою \"добре\": %.2f%%\n", goodPercentage);
    printf("Відсоток студентів з оцінкою \"відмінно\": %.2f%%\n", excellentPercentage);

    free(students);

    return 0;
}
