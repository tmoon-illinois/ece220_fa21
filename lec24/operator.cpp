#include <iostream>

using namespace std;
class Point{
    private:
        int x,y;
    public:
        Point(){
            x = 0; y=0;
        }
        Point(int _x, int _y){
            x = _x;
            y = _y;
        }
        Point operator+(int val){
            Point temp(x + val, y+val);
            return temp;
        }
        Point operator+(Point p){
            Point temp(x + p.x, y + p.y);
            return temp;
        }
        void show(){
            cout<<"x: "<<x<<", y: "<<y<<endl;
        }
};
int main(){
    Point p1(1,1);
    Point p2(5, 10);

    p1.show();
    p2.show();

    p2 = p1 + 10;
    p2.show();

    Point p3;
    p3 = p1 + p2;

    p3.show();
}
