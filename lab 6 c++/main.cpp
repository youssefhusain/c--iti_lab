#include <iostream>

using namespace std;

class person{
protected:
int id;
string name;
public:
person(){
id=0;
name="NONE";}
person(int idd,string nam){
id=idd;
name=nam;}
string getPersonName(){
return name;}
int getPresonId(){
return id;}
void setPersonName(string nam){
name=nam;}
void setPersonId(int idd){
id=idd;}
void print(){
cout<<"person id is "<<id<<endl;
cout<<"person name is "<<name<<endl;}};


class customer:public person{
double accNum;
public:
customer(){
accNum=0;}
customer(int idd,string nam,int num):person(idd,nam){
accNum=num;}
double getAcc(){
return accNum;}
void setAcc(double iddd){
accNum=iddd;}
void print(){
cout<<"customer id is "<<person::id<<endl;
cout<<"account number is "<<accNum<<endl;
cout<<"customer name is "<<person::name<<endl;}};


class employee:public person{
int salary;
public:
employee(){
salary=0;}
employee(int idd,string nam,int sal):person(idd,nam){
salary=sal;}
int getSal(){
return salary;}
void setSal(int sal){
salary=sal;}
void print(){
cout<<"employee id is "<<person::id<<endl;
cout<<"employee salary is "<<salary<<endl;
cout<<"employee name is "<<person::name<<endl;}};




int main()
{
    employee emp(10,"Youssf",100000);
    cout<<"Employee data is: "<<endl;
    emp.print();
    cout<<"CUstomer Data : "<<endl;
    customer cust(13,"ayman",100);
    cout<<"Customer data is: "<<endl;
    cust.print();
    cout<<"Person data is: "<<endl;
    person pers(15,"ahmed");
    pers.print();
    return 0;
}
