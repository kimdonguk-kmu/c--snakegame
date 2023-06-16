#ifndef GROWTH_H
#define GROWTH_H

#include "Item.h"

class Growth : public Item{
    public:
        Growth();
        void spawnGrowth(int map[30][60]);

        void despawnGrowth(int map[30][60]);

        
};

#endif