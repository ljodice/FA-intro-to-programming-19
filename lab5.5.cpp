#include <iostream>
#include <math.h>
#include <ctime>
using namespace std;

int main()
{
    int time = clock(); // Stores the computer's time in the variable time
    srand(time);
    int count, avg, sum, previousnum, numtimes;
    char keepgoing;
    int repeats = 0;
    cout << "how many times do you want the for loop to run?" << endl;
    cin >> count;
    numtimes = count;
    int firstnum = rand() % 3;
    cout << "the first number was " << firstnum << endl;
    count--;
    previousnum = firstnum;
    sum = previousnum;
    for (int count = numtimes; count > 1; count--)
    {
        int randnum = rand() % 3;
        if (randnum > previousnum)
        {
            cout << randnum << " was greater than the previous number" << endl;
            repeats=0;
        }
        else if (randnum < previousnum)
        {
            cout << randnum << " was less than the previous number" << endl;
            repeats=0;
        }
        else if (randnum == previousnum)
        {
            cout << "it was the same as the previous number " << randnum << endl;
            repeats++;
        }
        previousnum = randnum;
        sum = sum + randnum;
    }
    avg = sum / numtimes;
    cout << "the average number was " << avg << " the number of times that a number was repeated was " << repeats << endl;
    return 0;
}