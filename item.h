#ifndef ITEM_H
#define ITEM_H


#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Item {
    public:
        int positionX, positionY;
        int spawnTime =5;

        Item();
        void setPosition();
        int getPX();
        int getPY();
};

#endif