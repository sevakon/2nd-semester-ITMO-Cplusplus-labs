//
//  main.cpp
//  lab2_6&7
//
//  Copyright © 2019 Vsevolod Konyakhin. All rights reserved.
//

#include <iostream>
#include <string>
#include "function.h"
#include "stack.h"

void swapDemo () {
    std::cout << "//Swap Demonstration" << std::endl;
    long a, b;
    std::cout << "Input variable A: " << std::endl;
    std::cin >> a;
    std::cout << "Input variable B: " << std::endl;
    std::cin >> b;
    userSwap(a, b);
    std::cout << "Variable A after swap method: " << a << std::endl;
    std::cout << "Variable B after swap method: " << b << std::endl;
}

void stackDemo(int size) {
    std::cout << "//Stack Demonstration" << std::endl;
    Stack<std::string> myStack(size);
    myStack.pop();
    myStack.push("String 1");
    myStack.push("String 2");
    myStack.push("String 3");
    myStack.push("String 4");
    myStack.push("String 5");
    std::cout << myStack.pop() << std::endl;
}

int main(void) {
    int n = 3;
    swapDemo();
    stackDemo(n);
}
