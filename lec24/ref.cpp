#include <iostream>

using namespace std;
void swap(int *a, int *b){
    int temp;

    //a = a +100000;

    temp = *a;
    *a = *b;
    *b = temp;
}

void swap(int &a, int &b){
    int temp;

    a = a + 100000;
   

    temp = a;
    a = b;
    b = temp;
}

int main(){
    int a = 0, b = 10;

    swap(&a, &b); 
    cout<<"a: "<<a<<" b: "<<b<<endl;

    swap(a, b); 
    cout<<"a: "<<a<<" b: "<<b<<endl;
}
