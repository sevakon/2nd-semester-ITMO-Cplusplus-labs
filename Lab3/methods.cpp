//
//  methods.cpp
//  secondSemesterThirdLab
//
//  Copyright © 2019 Vsevolod Konyakhin. All rights reserved.
//

#include <stdio.h>
#include <string>
#include "header.h"
#include <iostream>
using namespace std;

Queue::Queue(Queue &q) : queueSize(q.queueSize){
    queue = new string[queueSize];
    head = 0;
    tail = 0;
}

Queue::Queue(int size) : queueSize(size){
    queue = new string[queueSize];
    head = 0;
    tail = 0;
}

Queue::Queue() : queueSize(10) {
    queue = new string[queueSize];
    head = 0;
    tail = 0;
}



int Queue::length() {
    return tail - head;
}

void Queue::push(string line) {
    if(line.length() > 255)
        cout << "String is too big" << endl;
    else{
        tail++;
        if (tail == queueSize)
            tail = 0;
        queue [tail] = line;
    }
}

void Queue::pop() {
    if (head == tail)
        cout << "Queue is empty" << endl;
    else {
        head++;
        if (head == queueSize)
            head = 0;
    }
}

void Queue::show() {
    for(int i = head + 1; i <= tail; i++) 
        cout << queue[i] << endl;
}

string Queue::first() {
    return queue[head + 1];
}

string Queue::last() {
    return queue[tail];
}

