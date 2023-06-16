#include "gate.h"

Gate::Gate(){
}

int Gate::getX1() { return x1;}
int Gate::getX2() { return x2;}
int Gate::getY1() { return y1;}
int Gate::getY2() { return y2;}

void Gate::makewallvector(int map[30][60]){
    for (int i = 0; i < 30; i++){
        for (int j = 0; j < 60; j++){
            if (map[i][j] == 1){
                wall.push_back(make_pair(i, j));
                //std::cout << i << " " << j << std::endl;
            }
        }
    }

}

void Gate::setPosition1(){
    int sz = wall.size();

    int r = rand() % sz;

    std::pair<int, int> p = wall[r];

    x1 = p.first;
    y1 = p.second;
}

void Gate::setPosition2(){
    int sz = wall.size();

    int r = rand() % sz;

    std::pair<int, int> p = wall[r];

    x2 = p.first;
    y2 = p.second;
}

void Gate::setDirection(Direction d){
    dir = d;
}

void Gate::spawnGate(int map[30][60]){
    setPosition1();
    setPosition2();
    while (x1 == x2 && y1 == y2){
        setPosition1();
        setPosition2();
    }
    map[getX1()][getY1()] = 7;
    map[getX2()][getY2()] = 7;

}

void Gate::despawnGate(int map[30][60]){
    map[getX1()][getY1()] = 1;
    map[getX2()][getY2()] = 1;

}