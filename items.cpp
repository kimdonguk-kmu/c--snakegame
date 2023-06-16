#include "item.h"
#include "poison.h"
#include "growth.h"

using namespace std;

Item::Item(){
    setPosition();
}
void Item::setPosition() {
    positionX = rand()%26+2;
    positionY = rand()%56+2;
}

int Item::getPX() {
    return positionX;
}

int Item::getPY() {
    return positionY;
}


Poison::Poison() : Item() {;}

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

Growth::Growth() : Item() {;}

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