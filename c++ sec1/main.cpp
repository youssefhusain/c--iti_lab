#include <iostream>
using namespace std;
int sem(int x=1, int y);
int x=1;
int main()
{
    int x=2;
    cout<<x<<endl;
    cout<<::x<<endl;
    int *ptr;
    ptr=new(int);

    ptr[0]=5;
    cout<<ptr[0]<<endl;
    sem(1);
    return 0;
}
int sem(int x, int y)
{
    cout<<x+y<<endl;
}
////////////////|| default argument given for parameter 2 of 'int sem(int, int)
