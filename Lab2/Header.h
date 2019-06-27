//
//  Header.h
//  sem2lab2
//
//  Copyright © 2019 Vsevolod Konyakhin. All rights reserved.
//

#ifndef Header_h
#define Header_h
struct Vector{
    float x;
    float y;
};

class Queue{
    static const int size = 10;
    int *queue;
    int head, tail;
public:
    Queue();
    Queue operator>>(int a); //push
    Queue operator<<(int a); //pop
    friend void show(Queue q);
};

void show(Queue q);

class planeSquare{
public:
    float x;
    float y;
    float a;
    float angle;
    float square;
    void show();
    friend bool operator==(planeSquare &t1, planeSquare &t2);
    //friend bool operator!=(planeSquare &t1, planeSquare &t2);
    bool operator!=(planeSquare &t2);
    planeSquare operator*(float t);
    planeSquare operator+(Vector a);
};

bool operator==(planeSquare &t1, planeSquare &t2);
//bool operator!=(planeSquare &t1, planeSquare &t2);

#endif /* Header_h */
