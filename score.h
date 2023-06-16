#include <ncursesw/ncurses.h>
#include <iostream>

using namespace std;

class Score{
    public:
        int cntLen=3, cntGrowth=0, cntPoison=0, cntGate=0, second=0;
        int goalLen, goalGrowth, goalPoison, goalGate;
        int level = 1;

        WINDOW* scoreboard;
        WINDOW* mission;

        Score(int Len, int growth, int poison, int gate);

        void plusGrow();
        void plusPoison();
        void plusGate();

        void tick();

        void printScoreBoard();
        void printMission();
};