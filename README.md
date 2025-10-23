# Домашнее задание к работе 9


## Условие задачи
Написать программу, выводящую на экран треугольник, нарисованный с помощью заданного с клавиатуры символа. Предусмотреть возможность изменения размеров фигуры путем задания ее размеров в количестве символов пользователем.
## 1. Алгоритм и блок-схема

### Алгоритм
1. **Начало**
2. Ввод символа
3. Ввод трёх сторон
4. Закрашенный треугольник или нет
5. Определяем самую длинную сторону как основание
6. Рисуем треугольник
7. **Конец**


## 2. Реализация программы

```
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <locale.h>

void drawTriangle() {
    setlocale(LC_ALL, "RUS");
    char symbol;
    int a, b, c;
    int fill;

    // Ввод символа
    printf("Введите символ: ");
    scanf(" %c", &symbol);

    // Ввод трех сторон
    printf("Введите сторону a: ");
    scanf("%d", &a);
    printf("Введите сторону b: ");
    scanf("%d", &b);
    printf("Введите сторону c: ");
    scanf("%d", &c);

    // Вопрос о заполнении
    printf("Закрашенный? (1-да, 0-нет): ");
    scanf("%d", &fill);

    printf("\n");


    // Определяем самую длинную сторону как основание
    int base, side1, side2;
    if (a >= b && a >= c) {
        base = a;
        side1 = b;
        side2 = c;
    }
    else if (b >= a && b >= c) {
        base = b;
        side1 = a;
        side2 = c;
    }
    else {
        base = c;
        side1 = a;
        side2 = b;
    }

    // Рисование треугольника
    for (int i = 0; i < height; i++) {
        // Позиции для левой и правой сторон
        double progress = (double)i / (height - 1);
        int left_pos = (int)(progress * (base - 1));
        int right_pos = base - (int)(progress * (base - 1)) - 1;

        // Рисование строки
        for (int j = 0; j < base; j++) {
            if (i == height - 1) {  // Основание
                printf("%c ", symbol);
            }
            else if (j == left_pos) {  // Левая сторона
                printf("%c ", symbol);
            }
            else if (j == right_pos) {  // Правая сторона
                printf("%c ", symbol);
            }
            else if (fill == 1 && j > left_pos && j < right_pos) {  // Внутренность
                printf("%c ", symbol);
            }
            else {
                printf("  ");  // Два пробела
            }
        }
        printf("\n");
    }
}

int main() {
    drawTriangle();
    return 0;
}
```


## 4. Информация о разработчике

Прохорова Виктория, бТИИ-251
