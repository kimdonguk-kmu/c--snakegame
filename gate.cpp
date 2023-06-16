#include "gate.h"

Gate::Gate(){
    setPosition();
}

void Gate::makewallvector(int map[30][60]){
    for (int i = 0; i < 30; i++){
        for (int j = 0; j < 60; j++){
            if (map[i][j] == 1){
                wall.push_back(make_pair(i, j));
            }
        }
    }

}

void Gate::setPosition(){
    int sz = wall.size();

    int r = rand() % sz;

    std::pair<int, int> p = wall[r];

    x = p.first;
    y = p.second;
}

void Gate::setDirection(Direction d){
    dir = d;
}

void Gate::spawnGate(int map[30][60]){
    setPosition();
    map[getX()][getY()] = 7;

}

void Gate::despawnGate(int map[30][60]){
    map[getX()][getY()] = 0;

}