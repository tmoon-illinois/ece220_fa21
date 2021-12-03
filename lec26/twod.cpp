#include <iostream>
#define MAX_SIZE 4
using namespace std;
class twodvec{
    private:
        double x,y;
    public:
        twodvec(double x_temp = 0, double _y = 0){x=x_temp; y=_y;}
        double operator[](int z) const{
            if(z==0) return x;
            else if(z==1) return y;
            else return 0;
        }
        void show(){cout<<x<<", "<<y<<endl;}
        twodvec operator+(const twodvec &b);
        twodvec operator*(const twodvec &b);
};

twodvec twodvec::operator+(const twodvec &b){
    twodvec temp(x + b.x, y + b.y );
    return temp;
}
twodvec twodvec::operator*(const twodvec &b){
    twodvec temp(x * b.x, y * b.y );
    return temp;
}
class VecArray{
    private:
        twodvec array[MAX_SIZE];
        int idx;
    public:
        VecArray(){idx = 0;}
        void AddElem(const twodvec& elem);
        void ShowAll();
        twodvec& operator[](int _idx);

};
void VecArray::AddElem(const twodvec& elem){
    if(idx == MAX_SIZE){
        cout<<"Overflowing!"<<endl;
        return;
    }
    array[idx] = elem;
    idx++;
}
void VecArray::ShowAll(){
    int i;
    cout<<"ShowAll()"<<endl;
    for(i=0; i<idx; i++){
        cout<<i<<": ";
//        array[i].show();
        cout<<"x:" << array[i][0] << ", y: " << array[i][1]<<endl;
    }
}
twodvec& VecArray::operator[](int _idx){
    return array[_idx];
}

int main(){
    twodvec p1(1,2), p2(2,3), p3;
    //p3 = p1 + p2; // --> p1.operator+(p2);

    p1.show();
    //p3.show();
    p2.show();
    p3.show();

    //p3 = p1 * p2;
    //p3.show();

    VecArray v;
    v.AddElem(p1);
    v.AddElem(p2);
    v.AddElem(p3);

    v.ShowAll();
    v[1].show();

}
