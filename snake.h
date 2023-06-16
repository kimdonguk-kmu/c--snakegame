#include <iostream>
#include <vector>
#include "Direction.hpp"
#include "gate.h"

using namespace std;

class Snake{
    private:
        bool dead = false;
        vector<pair<int, int>> body;
        Direction direction;
    public:
        const int MaxSnakeLen = 10;
        bool isgating = false;

        Snake(int initSize, int initX, int initY, Direction initDirection, int map[30][60]);
        
        Direction move(int map[30][60], Gate gt);
        void setDirection(Direction Direction);

        bool isdead();
        bool isgate();

        void plusbody(int map[30][60]);
        void minusbody(int map[30][60]);

        vector<pair<int, int>> getBody() const;
        Direction getDirection() const;
        int getLength() const;
};