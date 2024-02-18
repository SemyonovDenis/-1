#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

void initialize(int **array, int *size);
void insert(int **array, int *size, int index, int element);
void Remove(int **array, int *size, int index);
void print(const int *array, int size);
void findArithmetic(int **array, int *size, int **newArray, int *newSize);
void quit(int **array);

int main() {
    int *array = NULL;
    int size = 0;
    char choice;

    do {
        printf("\n(a) Инициализация массива.\n");
        printf("(b) Вставить новый элемент.\n");
        printf("(c) Убрать элемент.\n");
        printf("(d) Найти арифметические прогрессии.\n");
        printf("(e) Показать массив.\n");
        printf("(q) Выйти.\n");

        printf("Выбор: ");
        scanf(" %c", &choice);

        switch(choice) {
            case 'a':
                initialize(&array, &size);
                break;
            case 'b': {
                int index, element;
                printf("Индекс нового элемента: ");
                scanf("%d", &index);
                printf("Элемент: ");
                scanf("%d", &element);
                insert(&array, &size, index, element);
                break;
            }
            case 'c': {
                int index;
                printf("Индекс удаляемого элемента: ");
                scanf("%d", &index);
                Remove(&array, &size, index);
                break;
            }
            case 'd': {
                int *newArray = NULL;
                int newSize = 0;
                findArithmetic(&array, &size, &newArray, &newSize);
                printf("Изначальный массив:\n");
                print(array, size);
                printf("Числа с арифметическими прогрессиями:\n");
                print(newArray, newSize);
                free(newArray);
                break;
            }
            case 'e':
                print(array, size);
                break;
            case 'q':
                quit(&array);
                return 0;
            default:
                printf("Неверный выбор!\n");
        }
    } while(1);

    return 0;
}

void initialize(int **array, int *size) {
    printf("Размер массива: ");
    scanf("%d", size);

    if (*size <= 0) {
        printf("Только положительные числа!\n");
        return;
    }

    *array = (int *)malloc((*size) * sizeof(int));
    if (*array == NULL) {
        printf("Не получилось выделить память!\n");
        exit(1);
    }

    printf("Запишите %d элементов: \n", *size);
    for (int i = 0; i < *size; i++) {
        if (scanf("%d", &(*array)[i]) != 1) {
            printf("Только целые числа!\n");
            while (getchar() != '\n');
            free(*array);
            *array = NULL;
            *size = 0;
            return;
        }
    }
}

void insert(int **array, int *size, int index, int element) {
    if (index < 0 || index > *size) {
        printf("Индекс должен быть не больше %d!\n", *size);
        return;
    }

    *array = (int *)realloc(*array, (*size + 1) * sizeof(int));
    if (*array == NULL) {
        printf("Не получилось выделить память!\n");
        exit(1);
    }

    for (int i = *size; i > index; i--) {
        (*array)[i] = (*array)[i - 1];
    }

    (*array)[index] = element;
    (*size)++;
}

void Remove(int **array, int *size, int index) {
    if (index < 0 || index >= *size) {
        printf("Индекс должен быть не больше %d!\n", *size - 1);
        return;
    }

    for (int i = index; i < *size - 1; i++) {
        (*array)[i] = (*array)[i + 1];
    }

    *array = (int *)realloc(*array, (*size - 1) * sizeof(int));
    if (*array == NULL && *size > 1) {
        printf("Не получилось выделить память!\n");
        exit(1);
    }

    (*size)--;
}

void findArithmetic(int **array, int *size, int **newArray, int *newSize) {
    *newSize = 0;
    for (int i = 0; i < *size; i++) {
        int num = (*array)[i];
        int digit = num % 10;
        num /= 10;
        int diff = num % 10 - digit;
        bool isArithmeticProgression = true;
        while (num > 0) {
            int nextDigit = num % 10;
            if (nextDigit - digit != diff) {
                isArithmeticProgression = false;
                break;
            }
            digit = nextDigit;
            num /= 10;
        }
        if (isArithmeticProgression) {
            insert(newArray, newSize, *newSize, (*array)[i]);
            Remove(array, size, i);
            i--;
        }
    }
}

void print(const int *array, int size) {
    printf("Массив:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void quit(int **array) {
    if (*array != NULL) {
        free(*array);
        *array = NULL;
    }
    printf("Выход.\n");
}
