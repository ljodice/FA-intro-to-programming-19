#include <iostream>
#include <math.h>
#include <ctime>
using namespace std;

int main()
{
    int time = clock(); // Stores the computer's time in the variable time
    srand(time);
    int currentroom;
    int roomamount = 10;
    char rooms[roomamount];
    for (int i = 0; i < roomamount; i++)
    {
        rooms[i] = 'O';
    }
    int randexit = rand() % 11;
    rooms[randexit] = 'E';
    for (int i = 0; i < roomamount; i++)
    {
        cout << rooms[i] << "  ";
    }

    cout << "which room would you like to start in?" << endl;
   int start;
    cin >> start;
     currentroom = start;
    while (start == randexit)
    {
        cout << "Pick another room, the room selected was the exit" << endl;
        cin >> start;
    }
    rooms[start] = 'P';
    for (int i = 0; i < roomamount; i++)
    {
        cout << rooms[i] << "  ";
    }
   
    cout << "What direction would you like to go in?((1)right or (2)left)";
    int direction,placehold;
    do
    {
        cout << "would you like to go..." << endl
             << "1.)right" << endl
             << "2.)left" << endl;
        cin >> direction;
        if (direction == 1)
        {   
            
            rooms[currentroom]='O';
            placehold = currentroom;
            currentroom++;
            rooms[currentroom] = 'P';
            rooms[placehold] = 'O';
            
        }
        else if (direction == 2)
        {
            placehold = currentroom;
            currentroom--;
            rooms[currentroom] = 'P';
            rooms[placehold] = 'O';
            
        }
        if (currentroom != randexit)
        {
            cout << "current status of the game:" << endl;
            for (int i = 0; i < roomamount; i++)
            {
                cout << rooms[i] << "  ";
            }
        }
    } while (currentroom != randexit);
    cout << "you have found the exit" << endl
         << "GAME OVER" << endl;
}