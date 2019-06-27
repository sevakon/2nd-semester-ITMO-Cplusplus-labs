//
//  header.h
//  secondSemesterThirdLab
//
//  Copyright © 2019 Vsevolod Konyakhin. All rights reserved.
//

#ifndef header_h
#define header_h
#include <string>
using namespace std;

class Queue {
    int const queueSize;
    string *queue;
    int head, tail;
public:
    Queue(int size);
    Queue(Queue &q);
    Queue();
    int length();
    void push(string line);
    void pop();
    void show();
    string first();
    string last();
};

#endif /* header_h */
