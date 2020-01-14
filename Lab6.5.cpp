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
    bool hasKey = false;
    char rooms[roomamount];
    for (int i = 0; i < roomamount; i++)
    {
        rooms[i] = 'O';
    }
    int randexit = rand() % 11;
    rooms[randexit] = 'E';
    int randkey = rand() % 11;
    while (randkey == randexit)
    {
        randkey = rand() % 11;
    }
    rooms[randkey] = 'K';
    for (int i = 0; i < roomamount; i++)
    {
        cout << rooms[i] << "  ";
    }

    cout << "which room would you like to start in?" << endl;
    int start;
    cin >> start;
    
    while (start == randexit)
    {
        cout << "Pick another room, the room selected was the exit" << endl;
        cin >> start;
    }
    int attempts=0;
    rooms[start] = 'P';
    currentroom = start;
    int direction, placehold;
    do
    {
        if (rooms[randkey] == 'P')
        {
            if(hasKey==false){
            hasKey = true;
            cout << "you have found the key now you can leave" << endl;
            }
        }
        for (int i = 0; i < roomamount; i++)
        {
            cout << rooms[i] << "  ";
        }
        cout << "would you like to go..." << endl
             << "1.)right" << endl
             << "2.)left" << endl;

        cin >> direction;
        while(currentroom==0 && direction ==2){
                cout<<"invalid move"<<endl<<"please go to the left by pressing (1)";
                cin>>direction;
            }
        
        while(currentroom==9 && direction==1){
                cout<<"invalid move"<<endl<<"please go to the left by pressing (2)";
                cin>>direction;
            }
        if (direction == 1)
        {

            rooms[currentroom] = 'O';
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
        if (rooms[randexit] == 'P' && hasKey == false)
        {
            cout << "you do not have the key" << endl;
            if (direction == 1)
            {
                if (randexit == 0)
                {
                    cout << "invalid move" << endl;
                }
                else
                {
                    rooms[randexit + 1] = 'P';
                }
            }
            else if (direction == 2)
            {
                rooms[randexit - 1] = 'P';
                if (randexit == 0)
                {
                    cout << "invalid move" << endl;
                }
                else
                {
                    rooms[randexit - 1] = 'P';
                }
            }
        }
        if (rooms[randexit] == 'O' || rooms[randexit] == 'P')
        {
            rooms[randexit] = 'E';
        }
        attempts++;

    } while ((currentroom != randexit || hasKey == false));
    cout << "game over" << endl;
    if(attempts<15){
    cout << "YOU WIN!!" << endl;
    
    cout<<"it took "<<attempts<< " Turns"<<endl;
    }
    if(attempts>=15){
        cout<<"YOU LOSE"<<endl<<"it took you "<<attempts<<" moves and you needed to complete it in less than 15 turns"<<endl;
    }

}
