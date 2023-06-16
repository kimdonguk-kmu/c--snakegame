#ifndef OBJECT_H
#define OBJECT_H


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

class Object {
    public:
        int positionX, positionY;
        int spawnTime =5;
        vector<pair<int, int>> v;

        Object();
        void makevector(int map[30][60]);
        void setPosition();
        int getPX();
        int getPY();
};

#endif