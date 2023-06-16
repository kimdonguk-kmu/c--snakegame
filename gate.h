#include <iostream>
#include <vector>
#include "direction.hpp"

using namespace std;

class Gate{
    public:
        vector<pair<int, int>> wall;
        Direction dir;
        int x, y;

        Gate();

        int getX();
        int getY();
        void setDirection(Direction d);
        void setPosition();
        void makewallvector(int map[30][60]);
        void spawnGate(int map[30][60]);
        void despawnGate(int map[30][60]);
};