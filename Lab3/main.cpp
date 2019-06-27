//
//  main.cpp
//  secondSemesterThirdLab
//
//  Copyright © 2019 Vsevolod Konyakhin. All rights reserved.
//

#include <iostream>
#include "header.h"
#include <string>
using namespace std;

void showFirstAndLast(Queue &queue) {
    cout << "First element of the queue: " << queue.first() << endl;
    cout << "Last element of the queue: " << queue.last() << endl;
}

void showQueue(Queue &queue) {
    cout << "current queue's length: " << queue.length() << endl;
    queue.show();
}

int main(void) {
    cout << "Input size" << endl;
    int size;
    cin >> size;
    Queue queue(size);
    for(int i = 0; i < 3; i++) {
        string input;
        cin >> input;
        queue.push(input);
    }
//    queue.push("1st string");
//    queue.push("2nd string");
//    queue.push("3rd string");
    showQueue(queue);
    showFirstAndLast(queue);
    queue.pop();
    showQueue(queue);
    showFirstAndLast(queue);
}
