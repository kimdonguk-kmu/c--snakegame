#include "score.h"

using namespace std;

Score::Score(int len, int growth, int poison, int gate, int lv){
    goalLen = len;
    goalGrowth = growth;
    goalPoison = poison;
    goalGate = gate;
    level = lv;

    scoreboard = newwin(10, 60, 0, 60);
    mission = newwin(10, 60, 20, 60);
    wrefresh(scoreboard);
    wrefresh(mission);
}

void Score::plusGrow(){
    cntGrowth += 1;
    cntLen += 1;
    if (cntGrowth >= goalGrowth){
        mG = 'V';
    }
    if (cntLen >= goalLen){
        mB = 'V';
    }
}
void Score::plusPoison(){
    cntPoison += 1;
    cntLen -= 1;
    if (cntPoison >= goalPoison){
        mG = 'V';
    }
    if (cntLen <= goalLen){
        mB = 'X';
    }
}
void Score::plusGate(){
    cntGate += 1;
    if (cntGate >= goalGate){
        mG = 'V';
    }
}

void Score::tick(){
    second += 1;
}

void Score::printScoreBoard(){
    werase(scoreboard);
    wbkgd(scoreboard, COLOR_PAIR(level));
    wborder(scoreboard, '|', '|', '-', '-', '+', '+', '+', '+');
    mvwprintw(scoreboard, 1, 1, "Score Board");
    mvwprintw(scoreboard, 2, 1, "B:(CurrentLength)/(Max  Length) %d/%d", cntLen, 10); //maxsnakeLen = 10;
    mvwprintw(scoreboard, 3, 1, "+:(number of Growth): %d", cntGrowth);
    mvwprintw(scoreboard, 4, 1, "-:(number of Poison): %d", cntPoison);
    mvwprintw(scoreboard, 5, 1, "G:(number of Gate): %d", cntGate);
    mvwprintw(scoreboard, 6, 1, "Level: %d", level);
    mvwprintw(scoreboard, 7, 1, "time: %d", second);
    wrefresh(scoreboard);
}

void Score::printMission(){
    werase(mission);
    wbkgd(mission, COLOR_PAIR(level));
    wborder(mission, '|', '|', '-', '-', '+', '+', '+', '+');
    mvwprintw(mission, 1, 1, "Mission");
    mvwprintw(mission, 2, 1, "B:(CurrentLength)/(Goal Length) %d/%d (%c)", cntLen, goalLen, mB); 
    mvwprintw(mission, 3, 1, "+:(CurrentGrowth)/(Goal Growth): %d/%d (%c)", cntGrowth, goalGrowth, mG);
    mvwprintw(mission, 4, 1, "-:(CurrentPoison)/(Goal Poison): %d/%d (%c)", cntPoison, goalPoison, mP);
    mvwprintw(mission, 5, 1, "G:(CurrentGate)/(Goal Gate): %d/%d (%c)", cntGate, goalGate, mGT);
    wrefresh(mission);
}

bool Score::iscleared(){
    return (cntLen >= goalLen) && (cntGrowth >= goalGrowth) && (cntPoison >= goalPoison) && (cntGate >= goalGate);
}