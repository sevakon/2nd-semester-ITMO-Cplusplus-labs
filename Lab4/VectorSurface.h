//
//  VectorSurface.h
//  secondSemesterFourthLab
//
//  Created by Владимир Коняхин on 01/04/2019.
//  Copyright © 2019 Vsevolod Konyakhin. All rights reserved.
//

#ifndef VectorSurface_h
#define VectorSurface_h

#include "Surface.h"
#include <vector>

class VectorSurface : public Surface {
public:
    VectorSurface(Surface *surface, int size) : Surface (*surface) {
        moveVectors.resize(size);
        angles.resize(size);
        velocities.resize(size);
    }
    
    void addMoveAngle(int index, double angle, double velocity) {
        angles[index] = angle;
        velocities[index] = velocity;
    }
    
    void addMoveVector(int index, Dot vector) {
        moveVectors[index] = vector;
    }
    
    void performAction(int step) {
        for(int i = 0; i < velocities.size(); i++) {
            if(velocities[i] != 0) {
                resetDot(i, step * velocities[i] * cos(angles[i]), step * velocities[i] * sin(angles[i]));
            }
            if(moveVectors[i].x != 0 && moveVectors[i].y != 0)
                resetDot(i, step * moveVectors[i].x, step * moveVectors[i].y);
        }
    }
    
private:
    std::vector<Dot> moveVectors;
    std::vector<double> angles;
    std::vector<double> velocities;
};

#endif /* VectorSurface_h */
