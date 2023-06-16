#include <iostream>
#include <vector>

using namespace std;

class Svector{
    protected:
        int x, y;
    public:
        Svector(int x, int y);

        void setX(int x);
        void setY(int y);
        int getX(int x);
        int getY(int y);

        Svector& operator=(const Svector& s);
        Svector operator+(const Svector& s);
        Svector& operator+=(const Svector& s);
        Svector operator-(const Svector& s);
        Svector operator-=(const Svector& s);

        bool operator==(const Svector& s);
        bool operator!=(const Svector& s);
};