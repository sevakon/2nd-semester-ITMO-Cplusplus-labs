//
//  function.h
//  lab2_6&7
//
//  Copyright © 2019 Vsevolod Konyakhin. All rights reserved.
//

#ifndef function_h
#define function_h

template <typename T>
void userSwap(T& x, T& y) {
    T temp = x;
    x = y;
    y = temp;
}

#endif /* function_h */
