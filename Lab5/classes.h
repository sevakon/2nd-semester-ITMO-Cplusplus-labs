//
//  classes.h
//  fifthLab
//
//  Copyright © 2019 Vsevolod Konyakhin. All rights reserved.
//

#ifndef classes_h
#define classes_h

#include "figure.h"
#include "interface.h"
#include "math.h"
#include <iostream>
#include <vector>

using namespace std;

class EquilateralTriangle : public Figure {
public:
    
    double square() override {
        return sqrt(3) * side * side / 4.0;
    }
    
    double perimeter() override {
        return 3 * side;
    }
    
    double getSide() {
        return side;
    }
    
    double mass() const override {
        return objectMass;
    }
    
    CVector2D position() override {
        return vector;
    }
    
    
    void draw() override {
        cout << "Classname: " << classname() << endl;
        cout << "Memory Size: " << size() << endl;
        cout << "Triangle's side: " << getSide() << endl;
        cout << "Triangle's square: " << square() << endl;
        cout << "Triangle's perimeter: " << perimeter() << endl;
        cout << "Object's mass: " << mass() << endl;
        cout << "Vector x: " << position().x << endl;
        cout << "Vecror y: " << position().y << endl;
        
    }
    
    void initFromDialog() override {
        double triangleSide, mass, x, y;
        cout << "input triangle's side in double" << endl;
        cin >> triangleSide;
        cout << "input triangle's mass in double" << endl;
        cin >> mass;
        cout << "input triangle's x in double" << endl;
        cin >> x;
        cout << "input triangle's y in double" << endl;
        cin >> y;
        side = triangleSide;
        objectMass = mass;
        vector.x = x;
        vector.y = y;
        cout << "input finished" << endl;
        
    }
    
    const string classname() override {
        return name;
    }
    
    unsigned int size() override {
        return sizeof(this);
    }
    
private:
    double side;
    double objectMass;
    CVector2D vector;
    string name = "Equilateral Trinagle";
};



class Parallelogram : public Figure {
public:
    
    double square() override {
        return sin(angle) * firstSide * secondSide;
    }
    
    double perimeter() override {
        return 2.0 * (firstSide + secondSide);
    }
    
    
    double mass() const override {
        return objectMass;
    }
    
    CVector2D position() override {
        return vector;
    }
    

    
    void draw() override {
        cout << "Classname: " << classname() << endl;
        cout << "Memory Size: " << size() << endl;
        cout << "Parallelogram's first side: " << firstSide << endl;
        cout << "Parallelogram's second side: " << secondSide << endl;
        cout << "Parallelogram's perimeter: " << perimeter() << endl;
        cout << "Parallelogram's square: " << square() << endl;
        cout << "Parallelogram's angle: " << angle << endl;
        cout << "Object's mass: " << mass() << endl;
        cout << "Vector x: " << position().x << endl;
        cout << "Vecror y: " << position().y << endl;
        
    }
    
    void initFromDialog() override {
        double first, second, inputAngle, mass, x, y;
        cout << "input parallelogram's first side in double" << endl;
        cin >> first;
        cout << "input parallelogram's second side in double" << endl;
        cin >> second;
        cout << "input parallelogram's angle in double" << endl;
        cin >> inputAngle;
        angle = inputAngle;
        cout << "input parallelogram's mass in double" << endl;
        cin >> mass;
        cout << "input parallelogram's x in double" << endl;
        cin >> x;
        cout << "input parallelogram's y in double" << endl;
        cin >> y;
        firstSide = first;
        secondSide = second;
        objectMass = mass;
        vector.x = x;
        vector.y = y;
        cout << "input finished" << endl;
        
    }
    
    const string classname() override {
        return name;
    }
    
    unsigned int size() override {
        return sizeof(this);
    }
    
private:
    double firstSide;
    double secondSide;
    double angle;
    double objectMass;
    CVector2D vector;
    string name = "Parallelogram";
};

#endif /* classes_h */
