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

        Snake(int initSize, int initX, int initY, Direction initDirection, int map[30][60]);
        
        void move(int map[30][60]);
        void setDirection(Direction Direction);

        void plusbody(int map[30][60]);
        void minusbody(int map[30][60]);

        vector<pair<int, int>> getBody() const;
        Direction getDirection() const;
        int getLength() const;
};