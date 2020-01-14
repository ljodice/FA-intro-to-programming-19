#include <iostream>
#include <math.h>
#include <ctime>
using namespace std;

int main()
{
int time=clock();
srand(time);
int magicnum, guessnum;
 magicnum = rand() % 50;
 do
 {
     cout<<"guess number that is from 1-50"<<endl;
     cin>>guessnum;
     if (guessnum>magicnum)
     {
         cout<<"too High"<<endl;
     }
     else if(guessnum<magicnum)
     {
         cout<<"too low"<<endl;
     }
     
 } while (guessnum!=magicnum);
    cout<<"thanks for playing";

}