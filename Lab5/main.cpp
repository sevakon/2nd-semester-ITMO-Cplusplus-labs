//
//  main.cpp
//  fifthLab
//
//  Created by Владимир Коняхин on 15/04/2019.
//  Copyright © 2019 Vsevolod Konyakhin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include "classes.h"
#include "figure.h"

using namespace std;

int main(void) {
    vector<Figure*> figures;
    cout << "Input number of figures" << endl;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cout << "Clarify the figure's type: 1 if triangle, 0 if parallelogram" << endl;
        int type;
        cin >> type;
        EquilateralTriangle* triangle;
        Parallelogram* parallelogram;
        if(type == 1) {
            triangle = new EquilateralTriangle;
            triangle->initFromDialog();
            figures.push_back(triangle);
        }
        else {
            parallelogram = new Parallelogram;
            parallelogram->initFromDialog();
            figures.push_back(parallelogram);
        }
    }
    
    for(int i = 0; i < n; i++) {
        figures[i]->draw();
    }
    
    //center of masses
    cout << "center of masses: " << endl;
    double sumOfMasses = 0;
    double x = 0;
    double y = 0;
    for(int i = 0; i < n; i++) {
        x += figures[i]->position().x * figures[i]->mass();
        y += figures[i]->position().y * figures[i]->mass();
        sumOfMasses += figures[i]->mass();
    }
    x = x/sumOfMasses;
    y = y/sumOfMasses;
    cout << "x: " << x << endl;
    cout << "y: " << y << endl;
    
    cout << "Sorted: "<< endl;
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(figures[j]->mass() > figures[j+1]->mass()) {
                Figure* temp = figures[j];
                figures[j] = figures[j+1];
                figures[j+1] = temp;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        figures[i]->draw();
    }
}
