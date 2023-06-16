#ifndef GROWTH_H
#define GROWTH_H

#include "object.h"

class Growth : public Object{
    public:
        Growth();
        void spawnGrowth(int map[30][60]);
        void despawnGrowth(int map[30][60]);

        
};

#endif