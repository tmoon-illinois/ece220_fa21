#include <iostream>
using namespace std;
class Vehicle{
    public:
        virtual void ShowData() = 0;
};

class Airplane : public Vehicle{
    public:
        void ShowData(){
            cout<<"A"<<endl;
        }
};

int main(){
    Vehicle *ptr;
    Airplane a;

    ptr= &a;

    ptr->ShowData();

    //Vehicle v;

}


