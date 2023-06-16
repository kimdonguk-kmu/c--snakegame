#ifndef POISON_H
#define POISON_H

#include "item.h"

class Poison : public Item{
    public:
        Poison();
        void spawnPoison(int map[30][60]);
        void despawnPoison(int map[30][60]);
    
};

#endif