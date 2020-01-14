#include <iostream>
#include <math.h>
#include <ctime>
using namespace std;

int main()
{   
    //the stuff needed to use a rand num
    int time = clock(); // Stores the computer's time in the variable time
    srand(time);
    string cardVal, cardFaceType;
    char keepplaying;
    do
    {   
        //these numbers are used in the calculations of figureing out what the card is
        int exactcard = (rand() % 52) + 1;
        int cardvalnoface = (exactcard % 14)+1;
        int facetype = exactcard % 5;
        //this determines what the value of the card is
        //if it is either the jack,queen,king or ace then the name of the card is displayed rather than the number
        //else the number is printed out in the number's string form
        if (cardvalnoface == 11)
        {
            cardVal = "Jack";
        }
        else if (cardvalnoface == 12)
        {
            cardVal = "Queen";
        }
        else if (cardvalnoface == 13)
        {
            cardVal = "King";
        }
        else if (cardvalnoface == 1)
        {
            cardVal = "Ace";
        }
        else
        {
            cardVal = to_string(cardvalnoface);
        }
        //this is the part that determines the the card type
        if (facetype == 1)
        {
            cardFaceType = "Clubs";
        }
        else if (facetype == 2)
        {
            cardFaceType = "Diamonds";
        }
        else if (facetype == 3)
        {
            cardFaceType = "Hearts";
        }
        else if (facetype == 4)
        {
            cardFaceType = "Spades";
        }
        //this is the output that you get after it has ran
        cout << "the Card that was picked was a " << cardVal << " of " << cardFaceType << endl;
        //the rest of the loop is seeing if the user wants to continue
        cout << "would you like another card?(y or n)" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cin>>keepplaying;
    //this loops continues if the person types in the character y
    } while (keepplaying == 'y');
    cout << "thanks for playing" << endl;
}