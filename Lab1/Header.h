//
//  Header.h
//  Lab1
//
//  Copyright © 2019 Vsevolod Konyakhin. All rights reserved.
//

#ifndef Header_h
#define Header_h

struct Circle {
    float x;
    float y;
    float r;
};

struct Matrix {
    float array[3][3];
};

void integerPart1(float* a, int* b);

void integerPart2(float &a, int &b);

void inverse1(float *a, int *b);

void inverse2(float &a, int &b);

void move1(Circle *circle, float *x, float *y);

void move2(Circle &circle, float &x, float &y);

void multiply1(Matrix* matrix, float *k);

void multiply2(Matrix &matrix, float &k);

#endif /* Header_h */
