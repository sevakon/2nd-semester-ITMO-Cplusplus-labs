//
//  procedures.cpp
//  Lab1
//
//  Copyright © 2019 Vsevolod Konyakhin. All rights reserved.
//
#include "Header.h"

void integerPart1(float* a, int* b) {
    *b = *a;
}

void integerPart2(float &a, int &b) {
    b = a;
}

void inverse1(float *a, int *b) {
    float temp = *a;
    *a = (-1) * temp;
    int temp2 = *b;
    *b = (-1) * temp2;
}

void inverse2(float &a, int &b) {
    a = (-1) * a;
    b = (-1) * b;
}

void move1(Circle *circle, float *x, float *y) {
    circle->x+=*x;
    circle->y+=*y;
}

void move2(Circle &circle, float &x, float &y) {
    circle.x += x;
    circle.y += y;
}

void multiply1(Matrix* matrix, float *k) {
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            matrix->array[i][j] *= *k;
}

void multiply2(Matrix &matrix, float &k) {
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            matrix.array[i][j] *= k;
}



