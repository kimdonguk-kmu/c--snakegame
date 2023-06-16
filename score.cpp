#include "score.h"

using namespace std;

Score::Score(int len, int growth, int poison, int gate, int lv){
    goalLen = len;
    goalGrowth = growth;
    goalPoison = poison;
    goalGate = gate;
    level = lv;

    scoreboard = newwin(10, 40, 0, 60);
    mission = newwin(10, 40, 20, 60);
    wrefresh(scoreboard);
    wrefresh(mission);
}

void Score::plusGrow(){
    cntGrowth += 1;
    cntLen += 1;
}
void Score::plusPoison(){
    cntPoison += 1;
    cntLen -= 1;
}
void Score::plusGate(){
    cntGate += 1;
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
    mvwprintw(scoreboard, 3, 1, "G:(number of Growth): %d", cntGrowth);
    mvwprintw(scoreboard, 4, 1, "P:(number of Poison): %d", cntPoison);
    mvwprintw(scoreboard, 5, 1, "GT:(number of Gate): %d", cntGate);
    mvwprintw(scoreboard, 6, 1, "Level: %d", level);
    wrefresh(scoreboard);
}

void Score::printMission(){
    werase(mission);
    wbkgd(mission, COLOR_PAIR(level));
    wborder(mission, '|', '|', '-', '-', '+', '+', '+', '+');
    mvwprintw(mission, 1, 1, "Mission");
    mvwprintw(mission, 2, 1, "B:(CurrentLength)/(Goal  Length) %d/%d", cntLen, goalLen); 
    mvwprintw(mission, 3, 1, "G:(CurrentGrowth)/(Goal  Growth): %d/%d", cntGrowth, goalGrowth);
    mvwprintw(mission, 4, 1, "P:(CurrentPoison)/(Goal  Poison): %d/%d", cntPoison, goalPoison);
    mvwprintw(mission, 5, 1, "GT:(CurrentGate)/(Goal  Gate): %d/%d", cntGate, goalGate);
    wrefresh(mission);
}