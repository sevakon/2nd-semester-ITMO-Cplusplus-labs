//
//  Surface.h
//  secondSemesterFourthLab
//
//  Copyright © 2019 Vsevolod Konyakhin. All rights reserved.
//

#ifndef Surface_h
#define Surface_h

#include <vector>
#include "math.h"

class Surface {
public:
    
    Surface() {
    }
    
    //    Surface(const Surface &surface) {
//        this->dots = surface.dots;
//    }
    
    Surface(Surface *surface) {
        this->dots = surface->dots;
    }

    
    struct Dot {
        double x;
        double y;
    };
    
    
    void addDot(double x, double y) {
        Dot newDot = {x, y};
        dots.push_back(newDot);
    }
    
    Dot getDot(int i) {
        return dots[i];
    }
    
    void resetDot(int i, double x, double y) {
        dots[i].x = x;
        dots[i].y = y;
    }
    
    void removeDot(int i) {
        dots.erase(dots.begin() + i);
    }
    
    std::vector<Dot> getDots(Dot firstDot, Dot secondDot) {
        std::vector<Dot> someDots;
        for(int i = 0; i < dots.size(); i++) {
            if(dots[i].x >= firstDot.x && dots[i].x <= secondDot.x &&
               dots[i].y >= firstDot.y && dots[i].y <= secondDot.y) {
                someDots.push_back(dots[i]);
            }
        }
        return someDots;
    }
    
    std::vector<double> getDistancesFromPoint(int dotIndex) {
        std::vector<double> distances;
        for(int i = 0; i < dots.size(); i++) {
            if(i == dotIndex) {
                distances.push_back(0);
            }
            else {
                distances.push_back(distance(dots[dotIndex], dots[i]));
            }
        }
        return distances;
    }
    
    int getSize() {
        return dots.size();
    }
    
    
    double distance(Dot firstDot, Dot secondDot) {
        return sqrt((firstDot.x - secondDot.x)*(firstDot.x - secondDot.x) + (firstDot.y - secondDot.y)*(firstDot.y - secondDot.y));
    }
    
private:
    std::vector<Dot> dots;
};
#endif /* Surface_h */
