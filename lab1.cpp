//Luke Jodice Program: gAverage Calculator 
#include <iostream>
using namespace std;

int main()
{
 int x1,x2,x3,x4,sum,average;
 cout<< "Welcome to this Grade Calculator"<< endl<<endl;
cout<<"what are the grades that you have gotten?(one at a time)"<<endl; 
cin>>x1;
cin>>x2;
cin>>x3;
cin>>x4;
//calculations
sum = x1+x2+x3+x4;
average = sum/4;
cout<<"your grade average is "<<average<<endl;
    return 0;
}