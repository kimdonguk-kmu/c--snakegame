#include "svector.h"

using namespace std;

Svector::Svector(int vx=0, int vy=0) {setX(vx); setY(vy);}

void Svector::setX(int vx) { x = vx;}
void Svector::setY(int vy) { y = vy;}
