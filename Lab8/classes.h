//
//  classes.h
//  lab2_8
//
//  Created by Владимир Коняхин on 29/04/2019.
//  Copyright © 2019 Vsevolod Konyakhin. All rights reserved.
//

#ifndef classes_h
#define classes_h
class CPoint {
    
public:
    double x;
    double y;
    
    friend bool operator== (const CPoint &left, const CPoint &right);
};

bool operator== (const CPoint &left, const CPoint &right) {
    return (left.x == right.x && left.y == right.y);
}

#endif /* classes_h */
