//Luke Jodice
//Lab 3: Card Game
#include <iostream>
#include <math.h> // This library lets us access random numbers
#include <ctime>  // This library lets us access the computer's clock
using namespace std;

int main()
{
    //  DON'T CHANGE THESE FIRST 2 LINES, which are used to get the random numbers loaded
    int time = clock(); // Stores the computer's time in the variable time
    srand(time);        // Primes the pump for the random number generator

    int num1, num2, diff, num3, num4, diff2, num5, num6, diff3;
    int wallet = 100;
    int bet, bet2, bet3;
    string answer1, answer2, answer3;
    char rematch1, rematch2;
    //start of match 1
    num1 = rand() % 20; // Generates a random number between 0 and 20
    cout << "the first card is: " << num1 << endl;
    cout << "How much would you like to bet? remember it has to be between 1-100" << endl;
    cin >> bet;
    if (bet > 100 || bet < 1)
    {
        cout << "Enter a new number, the number that you put in is either more or less than you are able to bet" << endl;
         cin >> bet;
    }
   
    cout << "do you think the next card will be higher or lower than the current card?(Hi or Low)";
    cin >> answer1;
    num2 = rand() % 20; // Generates a random number between 0 and 20
    diff = num1 - num2;
    //conditional statement to determine if you win, lose or tie
    if (num1<num2 && (answer1 == "Hi" || answer1 == "hi"))
    {
        cout << "the first number was:" << num1<<endl
             << "the second number was:" << num2 << endl;
        cout << "the next number was higher than the first number" << endl
             << "you guessed correct" << endl;
        wallet = wallet + bet;
    }
    else if (num1<num2 && (answer1 != "hi" || answer1 !="Hi"))
    {
        cout << "the first number was:" << num1 << endl
             << "the second number was:" << num2 << endl;
        cout << "the number that was Higher was:" << num1;
        cout << "the number was lower than the first number" << endl
             << "you did not guess correct" << endl;
        wallet = wallet - bet;
    }
    else if (num1>num2 && (answer1 == "low" || answer1 == "Low"))
    {
        cout << "the first number was:" << num1 << endl
             << "the second number was:" << num2 << endl;
        cout << "you guessed correctly" << endl;
        wallet = wallet + bet;
    }
    else if (num1>num2 && (answer1 != "Low" || answer1 != "low"))
    {
        cout << "the first number was:" << num1 << endl
             << "the second number was:" << num2 << endl;
        cout << "you did not guess correctly" << endl;
        wallet = wallet - bet;
    }
    else if (num1==num2)
    {
        cout << "both of the numbers were:" << num1 << endl;
        cout << "both numbers were the same, this makes it a PUSH" << endl;
    }
    if (wallet > 0) //this is to make sure that the user has enough money to keep going
    {
        cout << "would you like to play again?(Y or N)" << endl;
        cin >> rematch1;
        if (rematch1 == 'Y' || rematch1 == 'y')
        { //start of game 2
            cout << "you currently have:$" << wallet << endl;
            num3 = rand() % 20; // Generates a random number between 0 and 20
            cout << "the first card is: " << num3 << endl;
            cout << "how much would you like to bet?" << endl
                 << "Make sure that it is a number between (0-" << wallet << ")" << endl;
            cin >> bet2;
            if (bet2 > 100 || bet2 < 1)
            {
                cout << "Enter a new number, the number that you put in is either more or less than you are able to bet" << endl;
                cin >> bet2;
            }
            
            num4 = rand() % 20; // Generates a random number between 0 and 20
            cout << "do you think the next card will be higher or lower than the current card?(Hi or Low)";
            int diff2 = num3 - num4;
            cin >> answer2;
            //conditional statement for game 2
            if (num3<num4 && (answer2 == "hi" || answer2 == "Hi"))
            {
                cout << "the first number was:" << num3 << endl
                     << "the second number was:" << num4 << endl;
                cout << "the next number was lower than the first number" << endl
                     << "you guessed correct" << endl;
                wallet = wallet + bet2;
            }
            else if (num3<num4 && (answer2 != "Hi" || answer2 != "hi"))
            {
                cout << "the first number was:" << num3 << endl
                     << "the second number was:" << num4 << endl;
                cout << "the number was lower than the first number" << endl
                     << "you did not guess correct" << endl;
                wallet = wallet - bet2;
            }
            else if (num3>num4 && (answer2 == "low" || answer2 == "Low"))
            {
                cout << "the first number was:" << num3 << endl
                     << "the second number was:" << num4 << endl;
                cout << "you guessed correctly" << endl;
                wallet = wallet + bet2;
            }
            else if (num3>num4 && (answer2 != "Low" || answer2 != "low"))
            {
                cout << "the first number was:" << num3 << endl
                     << "the second number was:" << num4 << endl;
                cout << "you did not guess correctly" << endl;
                wallet = wallet - bet2;
            }
            else if (num3==num4)
            {
                cout << "both of the numbers were:" << num3;
                cout << "both numbers were the same, this makes it a PUSH" << endl;
            }
            if (wallet > 0) //same conditional statement as before determineing if you have at least 1 dollar to bet
            {
                cout << "would you like to play again?(Y or N)" << endl;
                cin >> rematch2;
                if (rematch2 == 'y' || rematch2 == 'Y')
                {
                    num5 = rand() % 20; // Generates a random number between 0 and 20
                    cout << "the first card is: " << num5 << endl;
                    cout << "you currently have:$" << wallet << endl;
                    cout << "how much would you like to bet?" << endl
                         << "Make sure that it is a number between (0-" << wallet << ")" << endl;
                    cin >> bet3;
                    if (bet3 > 100 || bet3 < 1)
                    {
                        cout << "Enter a new number, the number that you put in is either more or less than you are able to bet" << endl;
                        cin >> bet3;
                    }
                    
                    num6 = rand() % 20;
                    cout << "do you think the next card will be higher or lower than the current card?(Hi or Low)";
                    diff3 = num5 - num6;
                    cin >> answer3;
                    //conditional statement for game 3
                    if (num5<num6 && (answer3 == "hi" || answer3 == "Hi"))
                    {
                        cout << "the first number was:" << num5 << endl
                             << "the second number was:" << num6 << endl;
                        cout << "the next number was lower than the first number" << endl
                             << "you guessed correct" << endl;
                        wallet = wallet + bet3;
                    }
                    else if (num5<num6 && (answer3 != "Hi" || answer3 != "hi"))
                    {
                        cout << "the first number was:" << num5 << endl
                             << "the second number was:" << num6 << endl;
                        cout << "the number was lower than the first number" << endl
                             << "you did not guess correct" << endl;
                        wallet = wallet - bet3;
                    }
                    else if (num5>num6 && (answer3 == "low" || answer3 == "Low"))
                    {
                        cout << "the first number was:" << num5 << endl
                             << "the second number was:" << num6 << endl;
                        cout << "you guessed correctly" << endl;
                        wallet = wallet + bet3;
                    }
                    else if (num5>num6 && (answer3 != "low" || answer3 != "Low"))
                    {
                        cout << "the first number was:" << num5 << endl
                             << "the second number was:" << num6 << endl;
                        cout << "you did not guess correctly" << endl;
                        wallet = wallet - bet3;
                    }
                    else if (num5==num6)
                    {
                        cout << "both numbers are:" << num6;
                        cout << "both numbers were the same, this makes it a PUSH" << endl;
                    }
                }
            }
            else
            {
                cout << "you have unsufficient funds to continue";
            }
        }
        else
        {
            cout << "thanks for playing" << endl;
        }
        
    }
    cout<<"thanks for playing"<<endl;
    return 0;
}