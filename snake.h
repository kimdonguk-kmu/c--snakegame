#include <iostream>
#include <vector>

using namespace std;
enum class Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

class Snake{
    private:
        vector<pair<int, int>> body;
        Direction direction;
    public:
        const int MaxSnakeLen = 10;

        Snake(int initSize, int initX, int initY, Direction initDirection);
        
        void move();
        void setDirection(Direction Direction);

        vector<pair<int, int>> getBody() const;
        Direction getDirection() const;
};