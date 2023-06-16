#ifndef POISON_H
#define POISON_H

#include "object.h"

class Poison : public Object{
    public:
        Poison();
        void spawnPoison(int map[30][60]);
        void despawnPoison(int map[30][60]);
    
};

#endif