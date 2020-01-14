#include <iostream>
using namespace std;

const float quarterVal = .25;
const float dimeVal = .1;
const float nickelVal = .05;
const float pennyVal = .01;

int main()
{
    string firstnam;
    char lastinitial;
    int numquart, numdime, numnickel, numpennies;
    cout << "What is your first name and initial?" << endl;
    cin >> firstnam >> lastinitial;
    cout << "Hello " << firstnam << " " << lastinitial << ", How many quarters, dimes, nickels, and pennies do you have?(just the number)" << endl;
    cin >> numquart >> numdime >> numnickel >> numpennies;
    float total = ((numquart * quarterVal) + (numdime + dimeVal) + (numnickel * nickelVal) + (numpennies * pennyVal));
    cout << "the value of the change is " << total << endl
         << "what would you like to do with your change?(Enter 1,2, or 3)" << endl
         << "1.)Take the cash as is" << endl
         << "2.)take a gift card" << endl
         << "3.)donate to a charity" << endl;
    int response;
    cin >> response;
    if (response == 1)
    {
        cout << "you have been dispensed the value:" << total << endl;
        cout << "you were given your money in " << endl
             << total << " in change" << endl;
        int numtwenties = total / 20;
        int numtens = (total / 10) - (numtwenties * 2);
        int numfives = (total / 5) - ((numtwenties * 4) + (numtens * 2));
        int numones = total - ((numtwenties * 20) + (numtens * 10) + (numfives * 5));
        int roundedtotal = total;
        cout << "you were given the amount of change:" << total - roundedtotal << endl;
        cout << "you were given the amount:$" << total << endl
             << "by denomination:" << endl
             << "$20's:" << numtwenties << endl
             << "$10's:" << numtens << endl
             << "$5's:" << numfives << endl
             << "$1's:" << numones << endl;
    }
    else if (response == 2)
    {
        cout << "you were given a gift card with the value of " << total * .95 << " due to a 5% you need to pay for the gift card" << endl;
    }
    else if (response == 3)
    {
        cout << "you have given the value of:" << total << "to a charity of your choice" << endl;
    }
    cout << "thank you for using the coinstar, Have a great day " << firstnam << ", " << lastinitial << endl
         << "keep in mind, that a monetary value can not be in the third decimal place so disregard that";

    return 0;
}