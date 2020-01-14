//Luke Jodice Num Guess Game
#include <iostream>
#include <math.h>
#include <ctime>
using namespace std;

int main()
{
    int time = clock(); // Stores the computer's time in the variable time
    srand(time);
    int magicnum, guessnum, timesguess, oldguess;
    char keepgoing = 'y';
    oldguess = 0;
    timesguess = 0;
    magicnum = rand() % 50;
    do
    {

        oldguess = guessnum;
        if (timesguess == 1) //this conditional statement only going to happen during the first loop because there is not a number that we can reference
        {
            cout << "Enter the number that you think is the magic number:(remember it is going to be between 0 and 50)" << endl;
            cin >> guessnum;
            if (guessnum > 50)
            {
                cout << "number too large has to be less than 50" << endl;
            }
            else if (abs(guessnum - magicnum) <= 5)
            {
                cout << "you are close" << endl;
            }
            else if (abs(guessnum - magicnum) >= 6)
            {
                cout << "too high" << endl;
            }
            else
            {
                cout << "this is not the right number" << endl;
            }
        }
        else if (timesguess > 1) //this is the defalut statement that will be ran
        {
            cout << "Enter the number that you think is the magic number:(remember it is going to be between 0 and 50)" << endl;
            cin >> guessnum;
            if (guessnum > 50)
            {
                cout << "number that was guessed was more than range, has to be less than 50" << endl;
            }
            else if ((abs(guessnum - magicnum)) < abs(oldguess - magicnum))
            {
                cout << "getting warmer" << endl;
            }
            else if ((abs(guessnum - magicnum)) > abs(oldguess - magicnum))
            {
                cout << "getting colder" << endl;
            }
            else if ((abs(guessnum - magicnum)) == (abs(oldguess - magicnum)))
            {
                cout << "you have picked the same number" << endl;
            }
            else
            {
                cout << "this is not the right number" << endl;
            }
        }

        if ((timesguess == 15) || (timesguess == 25)) //this condition is only done once the user does not guess the right number after 15 tries
        {
            cout << "would you like to keep playing?(y/n)" << endl;
            cin >> keepgoing;
            if (keepgoing == 'n')
            {
                cout << "thanks for playing" << endl;
            }
        }
        cout << "---------------------------------------------------" << endl;
        timesguess++;

    } while ((guessnum != magicnum) && (keepgoing == 'y'));

    if (keepgoing == 'n') //this condition is ran when the person gives up and does not want to play anymore
    {
        cout << "you have given up after " << timesguess << " guesses" << endl
             << " the number was " << magicnum << endl;
    }
    else //this is condition is ran when the user guesses the right number
    {
        cout << "You Win" << endl
             << "it only took you " << timesguess - 1 << " guesses" << endl;
    }
    return 0;
}