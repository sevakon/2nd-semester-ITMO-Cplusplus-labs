//
//  methods.cpp
//  sem2lab2
//
//  Copyright © 2019 Vsevolod Konyakhin. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "Header.h"

bool operator==(planeSquare &t1, planeSquare &t2) {
    return(t1.square == t2.square);
}

bool operator!=(planeSquare &t1, planeSquare &t2) {
    return!(t1.square == t2.square);
}

//new function
bool planeSquare::operator!=(planeSquare &t2) {
    return!(square == t2.square);
}

planeSquare planeSquare::operator*(float t) {
    a = a * t;
    return *this;
}

planeSquare planeSquare::operator+(Vector a) {
    x += a.x;
    y += a.y;
    return *this;
}

void planeSquare::show () {
    std::cout << "x: " <<  x << " y: " << y << " a: " << a << " angle: " << angle << " square: " << square << std::endl;
}

Queue::Queue() {
    queue = new int[size];
    head = 0;
    tail = 0;
}

void show(Queue q) {
    for(int i=q.head + 1; i < q.tail +1; i++)
        std::cout << q.queue[i] << " ";
    std::cout << std::endl;
}

//push
Queue Queue::operator>>(int a){
    tail++;
    if (tail == size)
        tail = 0;
    queue [tail] = a;
    return *this;
}

//pop
Queue Queue::operator<<(int a){
    if (head == tail)
        std::cout << "Queue is empty" << std::endl;
    else {
        head++;
        if (head == size)
            head = 0;
    }
    return *this;
}
