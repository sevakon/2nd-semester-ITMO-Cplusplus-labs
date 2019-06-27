//  main.cpp
//  Lab1
//  Copyright © 2019 Vsevolod Konyakhin. All rights reserved.
//

#include <iostream>
#include <math.h>
#include "Header.h"
using namespace std;

void getIntegerPart() {
    cout << "Input a float number" << endl;
    float number;
    int result1;
    int result2;
    cin >> number;
    integerPart1(&number, &result1);
    integerPart2(number, result2);
    cout << result1 << endl;
    cout << result2 << endl;
}

void inverse() {
    cout << "Input float and integer numbers for inverse" << endl;
    float a;
    int b;
    cin >> a >> b;
    inverse1(&a, &b);
    cout << a << endl;
    cout << b << endl;
    inverse2(a, b);
    cout << a << endl;
    cout << b << endl;
}

void moveCircle() {
    Circle circle;
    Circle* pointer = &circle;
    cout << "Input x, y, R of the circle using pointers" << endl;
    cin >> pointer->x >> pointer->y >> pointer->r;
    cout << "Input x, y vector" << endl;
    float x, y;
    cin >> x >> y;
    move1(&circle, &x, &y);
    cout << pointer->x << " " << pointer->y << " " << pointer->r << endl;
    cout << "Input x, y, R of the circle using links" << endl;
    cin >> pointer->x >> pointer->y >> pointer->r;
    cout << "Input x, y vector" << endl;
    cin >> x >> y;
    move2(circle, x, y);
    cout << pointer->x << " " << pointer->y << " " << pointer->r << endl;
}

void multiplyMatrix() {
    Matrix matrix;
    Matrix* pointer = &matrix;
    cout << "Input the 3x3 matrix using pointers" << endl;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            cin >> pointer->array[i][j];
    cout << "Your matrix is:" << endl;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++)
            cout << pointer->array[i][j] << " ";
        cout << endl;
    }
    cout << "Input the coefficient" << endl;
    float k;
    cin >> k;
    multiply1(&matrix, &k);
    cout << "New matrix is:" << endl;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++)
            cout << pointer->array[i][j] << " ";
        cout << endl;
    }
    
    
    cout << "Input the 3x3 matrix using links" << endl;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            cin >> pointer->array[i][j];
    cout << "Your matrix is:" << endl;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++)
            cout << pointer->array[i][j] << " ";
        cout << endl;
    }
    cout << "Input the coefficient" << endl;
    cin >> k;
    multiply1(&matrix, &k);
    cout << "New matrix is:" << endl;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++)
            cout << pointer->array[i][j] << " ";
        cout << endl;
    }
}

int main(int argc, const char * argv[]) {
    getIntegerPart();
    inverse();
    moveCircle();
    multiplyMatrix();
    return 0;
}
