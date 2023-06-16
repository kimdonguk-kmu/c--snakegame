#include "object.h"

Object::Object(){
}

void Object::makevector(int map[30][60]) {
    for (int i = 0; i < 30; i++){
        for (int j = 0; j < 60; j++){
            if (map[i][j] == 0){
                v.push_back(make_pair(i, j));
                //std::cout << i << " " << j << std::endl;
            }
        }
    }
}

void Object::setPosition() {
    int sz = v.size();

    int r = rand() % sz;

    std::pair<int, int> p = v[r];

    positionX = p.first;
    positionY = p.second;
    
}

int Object::getPX() {
    return positionX;
}

int Object::getPY() {
    return positionY;
}