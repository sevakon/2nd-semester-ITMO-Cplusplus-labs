//
//  main.cpp
//  lab2_8
//
//  Copyright © 2019 Vsevolod Konyakhin. All rights reserved.
//

#include <iostream>
#include <vector>
#include "classes.h"



template <class Iter, class Type>
bool anyOf (Iter first, const Iter &last, const Type& value) {
    while (first != last) {
        if(*first == value)
            return true;
        first++;
    }
    return false;
}

template <class Iter, class UnaryPredicate>
bool isPartitioned(Iter first, Iter last, UnaryPredicate p) {
    for (; first != last; ++first)
        if (!p(*first))
            break;
    for (; first != last; ++first)
        if (p(*first))
            return false;
    return true;
}

template <class Iter, class Predicate>
bool isPalindrome(Iter first, Iter last, Predicate p) {
    last--;
    while (first != last) {
        if(!p(*first, *last))
            return false;
        first++;
        if(!(first != last))
            break;
        last--;
    }
    return true;
}

template <class Type, int N>
class Predicate {
    
public:
    bool operator() (const Type a) {
        return a % N == 0;
    }
};

template <class Type>
class SecondPredicate {
    
public:
    bool operator() (const Type a, const Type b) {
        return a == b;
    }
};


int main(void) {
    std::vector<CPoint> v;
    CPoint point;
    point.x = 1.0;
    point.y = 2.0;
    v.push_back(point);
    point.x = 2.0;
    point.y = 2.0;
    v.push_back(point);
    point.x = 1.0;
    point.y = 2.0;

    v.push_back(point);
    std::cout << anyOf(v.begin(), v.end(), point) << std::endl;
    
    std::vector<int> vector;
    vector.push_back(4);
    vector.push_back(6);
    vector.push_back(3);
    
    std::cout << isPartitioned(vector.begin(), vector.end(), Predicate<int, 3>()) << std::endl;
    
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(3);
    vec.push_back(2);
    vec.push_back(1);
    
    std::cout << isPalindrome(vec.begin(), vec.end(), SecondPredicate<int>()) << std::endl;

}
