#include <iostream>


using namespace std;
void f(void){
    cout<<"void f"<<endl;
}
void f(int a){
    cout<<"f(int a)"<<endl;
}
/*
int f(int a){
    cout<<"int f(int a)"<<endl;
}
*/

int vol(int a , int b, int c = 1){
    return a*b*c;
}

int main(){
    f();
    f(10);

    cout<<vol(2, 2)<<endl;
    cout<<vol(2)<<endl;
}
