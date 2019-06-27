//
//  main.cpp
//  avl-tree
//
//  Copyright © 2019 Vsevolod Konyakhin. All rights reserved.
//

#include <iostream>
#include "avl.h"

int main(void) {
    AVL<int> t;
    t.insert(20);
    t.insert(25);
    t.insert(15);
    t.insert(10);
    t.insert(30);
    t.insert(5);
    t.insert(35);
    t.insert(67);
    t.insert(43);
    t.insert(21);
    t.insert(10);
    t.insert(89);
    t.insert(38);
    t.insert(69);
    
    for (auto it = t.begin(); it != t.end(); ++it)
        std::cout << *it << std::endl;
    
    std::cout <<"Size: "<< t.size() << std::endl;
    
    t.show();
    std::cout << '\n';
    
    t.remove(7);
    for (auto it = t.begin(); it != t.end(); ++it)
        std::cout << *it << std::endl;
    std::cout <<"Size: "<< t.size() << std::endl;
    
    auto it = t.find(21);
    std::cout << *it << std::endl;
}
