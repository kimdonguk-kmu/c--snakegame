#include "poison.h"
#include "growth.h"

using namespace std;


Poison::Poison() : Object() {;}

void Poison::spawnPoison(int map[30][60]){
    setPosition();
    while (map[getPX()][getPY()] != 0){
        setPosition();
    }
    map[getPX()][getPY()] = 6;
}

void Poison::despawnPoison(int map[30][60]){
    map[getPX()][getPY()] = 0;
}

Growth::Growth() : Object() {;}

void Growth::spawnGrowth(int map[30][60]){
    setPosition();
    while (map[getPX()][getPY()] != 0){
        setPosition();
    }
    map[getPX()][getPY()] = 5;
}

void Growth::despawnGrowth(int map[30][60]){
    map[getPX()][getPY()] = 0;
}