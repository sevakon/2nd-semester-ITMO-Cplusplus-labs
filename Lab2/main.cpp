//
//  main.cpp
//  sem2lab2
//
//  Copyright © 2019 Vsevolod Konyakhin. All rights reserved.
//

#include <iostream>
#include "Header.h"
using namespace std;

void inputPart(planeSquare &square1, planeSquare &square2) {
    cout << "Input x, y, a, angle of the first square" << endl;
    cin >> square1.x >> square1.y >> square1.a >> square1.angle;
    square1.square = square1.a * square1.a;
    cout << "First square: " << endl;
    square1.show();
    
    cout << "Input x, y, a, angle of the second square" << endl;
    cin >> square2.x >> square2.y >> square2.a >> square2.angle;
    square2.square = square2.a * square2.a;
    cout << "Second square: " << endl;
    square2.show();
}
void equalPart(planeSquare &square1, planeSquare &square2) {
    if(square1 == square2)
        cout << "Squares are equal" << endl;
    if(square1 != square2)
        cout << "Squares are not equal" << endl;
}

void coefficientPart(planeSquare &square1) {
    float k;
    cout << "Input a coefficient" << endl;
    cin >> k;
    square1*k;
    square1.square = square1.a * square1.a;
    cout << "First square: " << endl;
    square1.show();
}

void vectorPart(planeSquare &square2, Vector &vector) {
    cout << "Input x, y" << endl;
    cin >> vector.x >> vector.y;
    square2+vector;
    cout << "Second square: " << endl;
    square2.show();
}

void planeSquarePart() {
    planeSquare square1;
    planeSquare square2;
    Vector vector;
    inputPart(square1, square2);
    equalPart(square1, square2);
    coefficientPart(square1);
    vectorPart(square2, vector);
}

void queuePart() {
    Queue queue;
    queue<<1;
    for(int i = 1; i < 5; i++)
        queue>>i;
    show(queue);
    queue<<1;
    show(queue);
    queue>>55;
    show(queue);
}

int main(int argc, const char * argv[]) {
    planeSquarePart();
    queuePart();
}
