#include <iostream>
#include <cstring>

using namespace std;
class Person{
    private:
        //char name[20];
        char *name;
        int age;
    public:
        Person(char const  *_name, int _age){
            cout<<"Calling constructor "<<endl;
            name = new char[strlen(_name)+1];
            strcpy(name, _name);
            age = _age;
        }
        Person(){
            strcpy(name, "");
            age = 0;

        }
        void show();
        ~Person(){
            cout<<"Calling destructor"<<endl;
            delete name;
        }
};

void Person::show(){
    cout<<"Name: "<< name<<endl;
    cout<<"Age: "<< age<< endl;
}
int main(){
    Person p1("Alice", 10);
    p1.show();
    
    Person p2("Bob", 10);
    p2.show();
/*
    Person p2;
    p2.show();
    */
}
