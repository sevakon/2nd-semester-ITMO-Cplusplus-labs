//
//  main.cpp
//  secondSemesterFourthLab
//
//  Copyright © 2019 Vsevolod Konyakhin. All rights reserved.
//

#include <iostream>

#include "Surface.h"
#include "VectorSurface.h"

using namespace std;

void addDots(Surface *surface){
    for(double i = 0.0; i < 4.0; i += 1.0)
        for(double j = 0.0; j < 4.0; j += 1.0)
            surface->addDot(i, j);
}

void printDots(Surface *surface) {
    cout << "added dots are: " << endl;
    for(int i = 0; i < 16; i++) {
        cout  << i+1 << ": " << endl;
        cout << "x: " << surface->getDot(i).x << " y: " << surface->getDot(i).y << endl;
    }
}

void getDistances(Surface *surface, int index) {
    vector<double> distances = surface->getDistancesFromPoint(index);
    cout << "Distances from point #" << index << endl;
    for(int i = 0; i < distances.size(); i++) {
        cout << distances[i] << " ";
    }
    cout << endl;
}

void getCollectedDots(Surface *surface, Surface::Dot firstDot, Surface::Dot secondDot) {
    vector<Surface::Dot> collectedDots = surface->getDots(firstDot, secondDot);
    cout << "Collected Dots are:" << endl;
    for(int i = 0; i < collectedDots.size(); i++) {
        cout << "x: " << collectedDots[i].x << " y: " << collectedDots[i].y << endl;
    }
}

void vectorSurfaceTest(VectorSurface *vectorSurface) {
    cout << "VectorSurface Test Started" << endl;
    Surface::Dot vector = {2.0, 3.0};
    vectorSurface->addMoveVector(0, vector);
    vectorSurface->addMoveAngle(1, 2.0, 4.0);
    vectorSurface->performAction(2);
    cout << "dots after two iterations" << endl;
    for(int i = 0; i < 16; i++) {
        cout  << i+1 << ": " << endl;
        cout << "x: " << vectorSurface->getDot(i).x << " y: " << vectorSurface->getDot(i).y << endl;
    }
}

void getDots() {}

int main(void) {
    Surface *surface = new Surface();
    addDots(surface);
    printDots(surface);
    getDistances(surface, 5);
    Surface::Dot firstDot = {1.0, 2.0};
    Surface::Dot secondDot = {2.0, 3.0};
    getCollectedDots(surface, firstDot, secondDot);
    VectorSurface *vectorSurface = new VectorSurface(surface, surface->getSize());
    vectorSurfaceTest(vectorSurface);
//    delete surface; delete [] or ' '
    delete surface;
}
