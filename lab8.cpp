//Luke Jodice LAB 8
#include <iostream>
#include <math.h>
#include <ctime>
using namespace std;

void print(int list[])
{
    for (int i = 0; i < 10; i++)
    {
        if (list[i] >= 0)
        {
            cout << list[i]<<" ";
        }
        else
        {
            cout << "<-BLANK-> ";
        }
    }
    int valent=0;
        for(int i=0; i<10;i++){
            if(list[i]!=-1){
                valent++;
            }
        }
        cout<<endl<<"number of valid entries:"<<valent;
}

int maxval(int list[])
{
    int max = list[0];
    for (int i = 1; i < 10; i++)
    {
        if (list[i] > max)
        {
            max = list[i];
        }
    }
    return max;
}

int numlookup(int list[], int searchval)
{
    int timesseen = 0;
    for (int i = 0; i < 10; i++)
    {
        if (list[i] == searchval)
        {
            timesseen++;
        }
    }
    return timesseen;
}

void numdel(int list[], int numdel)
{
    int timesdel=0;
    for (int i = 0; i < 10; i++)
    {
        if (list[i] == numdel)
        {
            list[i] = -1;
            timesdel++;
        }
    
    }
   if(timesdel==0){
       cout<<"there was no "<<numdel<<"'s in the array"<<endl;
   } 
}
void addnum(int list[], int numadd)
{
     int numfull=0;
    for (int i = 0; i < 10; i++)
    {
       
        if (list[i] == -1)
        {
            list[i] = numadd;
            break;
        }
        else{
            numfull++;
        }
       
    }
     if (numfull==10){
            cout<<"there is no avaliable slots"<<endl;
        }
}
int main()
{
    int time = clock(); // Stores the computer's time in the variable time
    srand(time);
    int count = 10;
    int list[count];
    for (int i = 0; i < 10; i++)
    {
        list[i] = rand() % 11;
    }
    for (int i = 0; i < 10; i++)
    {
        cout << list[i] << " ";
    }
    int decision;
    do
    {
        cout <<endl<< "what would you like to do with these numbers?" << endl;
        cout << "1.)print array" << endl
             << "2.) compute the max" << endl
             << "3.) number lookup" << endl
             << "4.) delete from the array" << endl
             << "5.) add to the array" << endl
             << "6.)quit" << endl;
        cin >> decision;
        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
        if (decision == 1)
        {
            print(list);
        }
        else if (decision == 2)
        {
            cout << "the max value was " << maxval(list) << endl;
        }
        else if (decision == 3)
        {
            cout << "what value would you like to search for in the array" << endl;
            int searchval;
            cin >> searchval;
            cout << "the number of times that " << searchval << " was seen in the array was " << numlookup(list, searchval) << endl;
        }
        else if (decision == 4)
        {
            int numdele;
            cout << "what number would you like to delete from the array?" << endl;
            for(int i=0; i<10;i++){
                if(list[i]!=-1){
                cout<<list[i]<<" ";
                }
                else{
                    cout<<"<empty> ";
                }
            }
            cout<<endl;
            cin >> numdele;
            numdel(list,numdele);
        }
        else if (decision == 5)
        {
            int numadd;
            cout << "what number would you like to add?" << endl;
            cin >> numadd;
            addnum(list, numadd);
        }
        else if (decision != 6)
        {
            cout << "invalid option" << endl;
        }
        
    } while (decision != 6);
    cout<<"thank you for using this!! :)"<<endl;
}