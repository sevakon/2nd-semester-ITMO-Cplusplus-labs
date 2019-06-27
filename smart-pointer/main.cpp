//
//  main.cpp
//  smart_pointer
//
//  Copyright © 2019 Vsevolod Konyakhin. All rights reserved.
//

#include <iostream>

template <typename T>
class smart_pointer {
    T* my_obj;
    
public:
    smart_pointer(T* obj) : my_obj(obj) {}
    
    //Destructor
    ~smart_pointer() {
        delete my_obj;
    }
    
    T* operator->() {
        return my_obj;
    }
    
    T& operator*() {
        return *my_obj;
    }
};

int main(int argc, const char * argv[]) {
    
    smart_pointer<int> pointer(new int(5));
    std::cout << *pointer << '\n';
    return 0;
}

