#include <iostream>
using namespace std;
class MyStack{
    private:
        int TOS;
        char *data;
    public:
        MyStack(int _size =3){
            TOS = -1;
            data = new char[_size];
        }
        ~MyStack(){delete []data;}
        void push(const char &value){
            TOS++;
            data[TOS] = value;
        }
        char top(){return data[TOS];}
        void pop(){
            TOS--;
        }
        bool empty(){
            if(TOS==-1) return true;
            else return false;
        }
};

class Point{
    private:
        int x,y;
    public:
        Point(){x=0;y=0;}
        Point(int _x, int _y){x=_x;y=_y;}
        void show(){cout<<x<<","<<y<<endl;}
};
int main(){
    MyStack s;
    s.push('a');
    s.push('b');
    s.push('c');
    s.push('d');

    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
    s.pop();
}




