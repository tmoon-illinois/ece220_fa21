#include <iostream>

using namespace std;
class Point{
    private: 
        int x,y;
    public:
        Point(int _x=0, int _y=0){x=_x; y=_y;}
        Point(const Point &p){
            x = p.x;
            y = p.y;
        }
        void ShowPosition(){cout<<x<<", "<<y<<endl;}
        Point operator+(int val){
            Point temp(x+val, y+val);
            return temp;
        }
        Point operator+(const Point &p){
            Point temp(x+p.x, y+p.y);
            return temp;
        }
        Point operator=(const Point &p){
            x = p.x;
            y = p.y;
            return *this;
        }
        friend Point operator+(int val, Point& p);
};
Point operator+(int val, Point& p){
    return Point(p.x+val, p.y+val);
}
int main(){
    Point p1(1,2);

    Point p2 = p1 +10;
    p2.ShowPosition();

    Point p3;
    p3 = 10 + p1;
    p3.ShowPosition();
}

