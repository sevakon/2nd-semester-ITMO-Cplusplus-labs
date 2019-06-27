//
//  class.h
//  lab2_6&7
//
//  Copyright © 2019 Vsevolod Konyakhin. All rights reserved.
//

#ifndef stack_h
#define stack_h

#include <iostream>

template <class Type>
class Stack {
    
private:
    Type* stackPointer;
    const int size;
    int top;
public:
    Stack(int maxSize) : size(maxSize) {
        stackPointer = new Type[size];
        top = 0;
    }
    
    void push (const Type& value) {
        try {
            if (top < size) {
                stackPointer[top++] = value;
                std::cout << value << " pushed"<< std::endl;
            } else throw 1;
        } catch (int i) {
            std::cout << value << " was not pushed. Error " << i << ": Stack Overflow"<< std::endl;
        }
    }
    
    Type pop() {
        Type t;
        try {
            if (top > 0) {
                return stackPointer[--top];
            } else throw 2;
        } catch (int i) {
            std::cout << "Error " << i << ": Stack is empty"<< std::endl;
        }
        return t;
    }
};



#endif /* stack_h */
