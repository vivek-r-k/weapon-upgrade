#include<iostream>
using namespace std;

class school
{
private:
    int id;
    int marks;
public:
    char name[10];
    int roll;
    void details_s();
    void display();
protected:
    string address;
};
void school::details_s()
{
    cout<<"Enter the id\n";
    cin>>id;
    cout<<"Enter the marks\n";
    cin>>marks;
}
void school::display()
{
    cout<<"Id and marks are "<<id<<"\t"<<marks<<endl;
}
class sec:public school
{
public:
    void set_det(string add)
    {
        address = add;
        cout<<"The address is "<<address<<endl;
    }
};
int main()
{
    string add;
    school s;
    sec s1;
    s.details_s();
    s.display();
    cout<<"Enter the address\n"<<endl;
    cin>>add;
    s1.set_det(add);
    return 0;
}


