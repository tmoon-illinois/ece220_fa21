#include <iostream>
#include <cstring>
using namespace std;
class Person{
    private:
        char *name;
        int age;
    public:
        Person(char const  *_name, int _age){
            name = new char[ strlen(_name) + 1];
            strcpy(name, _name);
            age = _age;
        }
        virtual ~Person(){
            delete []name;
        }
        virtual void print(){
            cout<<"Name: "<<name<<endl;
            cout<<"Age: "<<age<<endl;
        }
        char* getName(){return name;}
        int getAge(){return age;}
};

class Student: public Person{
    private:
        char *major;
        float gpa;
    public:
        Student(char const *_name, int _age, char const *_major, float _gpa): Person(_name, _age){
            major = new char[ strlen(_major) + 1];
            strcpy(major, _major);
            gpa = _gpa;
        }
        ~Student(){
            delete []major;
        }
        void print(){
            cout<<"Name: "<<getName()<<endl;
            cout<<"Age: "<<getAge()<<endl;
            cout<<"Major: "<<major<<endl;
            cout<<"GPA: "<<gpa<<endl;
        }
};
class Faculty: public Person{
    private:
        char *office;
        double salary;
    public:
        Faculty(char const *_name, int _age, char const *_office, float _salary): Person(_name, _age){
            office = new char[ strlen(_office) + 1];
            strcpy(office, _office);
            salary = _salary;
        }
        ~Faculty(){
            delete []office;
        }
        void print(){
            cout<<"Name: "<<getName()<<endl;
            cout<<"Age: "<<getAge()<<endl;
            cout<<"OFfice : "<<office<<endl;
            cout<<"Salary: "<<salary<<endl;
        }
};

int main(){
    Student a("Alice", 22, "ECE", 3.9);

    Person *p[10];

    p[0] = new Student("Alice", 22, "ECE", 3.9);
    p[1] = new Faculty("Bob", 22, "ECEB-3030", 100000000.00);
    p[2] = new Student("Cris", 22, "ECE", 3.9);
    p[3] = new Student("David", 22, "ECE", 3.9);

    for(int i=0;i<4;i++)
        p[i]->print();

    for(int i=0;i<4;i++)
        delete p[i];



}
