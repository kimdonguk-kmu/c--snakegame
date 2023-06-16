#ifndef GATE_H
#define GATE_H

#include <iostream>
#include <vector>
#include "Direction.hpp"

using namespace std;

class Gate{
    public:
        vector<pair<int, int>> wall;
        Direction dir;
        int x1, y1;
        int x2, y2;

        Gate();

        int getX1();
        int getY1();
        int getX2();
        int getY2();
        void setDirection(Direction d);
        void setPosition1();
        void setPosition2();
        void makewallvector(int map[30][60]);
        void spawnGate(int map[30][60]);
        void despawnGate(int map[30][60]);
};

#endif