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

    // Вычисление высоты
    double p = (a + b + c) / 2.0;
    double area = sqrt(p * (p - a) * (p - b) * (p - c));
    int height = (int)(2 * area / base);

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