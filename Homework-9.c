#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <locale.h>

void drawTriangle() {
    setlocale(LC_ALL, "RUS");
    char symbol;
    int a, b, c;
    int fill;

    // ���� �������
    printf("������� ������: ");
    scanf(" %c", &symbol);

    // ���� ���� ������
    printf("������� ������� a: ");
    scanf("%d", &a);
    printf("������� ������� b: ");
    scanf("%d", &b);
    printf("������� ������� c: ");
    scanf("%d", &c);

    // ������ � ����������
    printf("�����������? (1-��, 0-���): ");
    scanf("%d", &fill);

    printf("\n");


    // ���������� ����� ������� ������� ��� ���������
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

    // ���������� ������
    double p = (a + b + c) / 2.0;
    double area = sqrt(p * (p - a) * (p - b) * (p - c));
    int height = (int)(2 * area / base);

    // ��������� ������������
    for (int i = 0; i < height; i++) {
        // ������� ��� ����� � ������ ������
        double progress = (double)i / (height - 1);
        int left_pos = (int)(progress * (base - 1));
        int right_pos = base - (int)(progress * (base - 1)) - 1;

        // ��������� ������
        for (int j = 0; j < base; j++) {
            if (i == height - 1) {  // ���������
                printf("%c ", symbol);
            }
            else if (j == left_pos) {  // ����� �������
                printf("%c ", symbol);
            }
            else if (j == right_pos) {  // ������ �������
                printf("%c ", symbol);
            }
            else if (fill == 1 && j > left_pos && j < right_pos) {  // ������������
                printf("%c ", symbol);
            }
            else {
                printf("  ");  // ��� �������
            }
        }
        printf("\n");
    }
}

int main() {
    drawTriangle();
    return 0;
}