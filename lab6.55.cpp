#include <iostream>
#include <math.h>
#include <ctime>
using namespace std;

int main()
{
    int time = clock(); // Stores the computer's time in the variable time
    srand(time);
    int currentcordX, currentcordY, draMovex, draMovey, dragoninc, direction;
    currentcordX = 0;
    currentcordY = 0;
    int randexitcoor = (rand() % 10) + 1;
    int randexitcoor2 = (rand() % 10) + 1;
    int dragonx = (rand() % 10) + 1;
    int dragony = (rand() % 10) + 1;
    int keyx = (rand() % 10) + 1;
    int keyy = (rand() % 10) + 1;
    int swordx = (rand() % 10) + 1;
    int swordy = (rand() % 10) + 1;
    dragoninc = 0;
    bool dragonAlive = true;
    bool hasKey = false;
    bool hasSword = false;
    bool isAlive = true;
    char rooms[10][10];

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            rooms[i][j] = 'O';
        }
    }
    rooms[dragonx][dragony] = 'D';
    if (currentcordX == dragonx && currentcordY == dragony)
    {
        currentcordX = currentcordX + 1;
    }
    rooms[keyx][keyy] = 'O';
    if (currentcordX == keyx && currentcordY == keyy)
    {
        currentcordX = currentcordX + 1;
    }
    rooms[currentcordX][currentcordY] = 'P';
    rooms[randexitcoor][randexitcoor2] = 'E';
    swordx = (rand() % 10) + 1;
    swordy = (rand() % 10) + 1;
    rooms[swordx][swordy] = 'S';
    while ((swordx == dragonx && swordy == dragony) || ((swordx == currentcordX && swordy == currentcordY) || (swordx == randexitcoor && swordy == randexitcoor2)))
    {
        swordx = (rand() % 10) + 1;
        swordy = (rand() % 10) + 1;
        rooms[swordx][swordy] = 'S';
    }

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << rooms[i][j] << "  ";
        }
        cout << endl
             << endl;
    }
    while (rooms[randexitcoor][randexitcoor2] != 'P' && isAlive == true)
    {
        cout << "Key:" << endl
             << "P=You(as a character)" << endl
             << "E=Exit" << endl
             << "X=Dragon" << endl
             << "K=Key" << endl;
        cout << "which direction would you like to go in?" << endl
             << "1.)up"
             << "2.)down"
             << "3.)right"
             << "4.)left";

        cin >> direction;

        while ((currentcordX == 0 && direction == 1) || (currentcordX == 9 && direction == 2))
        {
            cout << "can not go that way please try another way" << endl;
            cin >> direction;
        }
        while ((currentcordY == 0 && direction == 4) || (currentcordY == 9 && direction == 3))
        {
            cout << "can not go that way please try another way" << endl;
            cin >> direction;
        }
        if (direction == 1)
        {
            rooms[currentcordX][currentcordY] = 'X';
            currentcordX = currentcordX - 1;
            if (rooms[currentcordX][currentcordY] == 'X')
            {
                cout << "you Have fallen through the floor into a spike trap" << endl;
                isAlive = false;
            }

            rooms[currentcordX][currentcordY] = 'P';
        }
        else if (direction == 2)
        {
            rooms[currentcordX][currentcordY] = 'X';
            currentcordX = currentcordX + 1;
            if (rooms[currentcordX][currentcordY] == 'X')
            {
                cout << "you Have fallen through the floor into a spike trap" << endl;
                isAlive = false;
            }
            rooms[currentcordX][currentcordY] = 'P';
        }

        if (direction == 3)
        {
            rooms[currentcordX][currentcordY] = 'X';
            currentcordY = currentcordY + 1;
            if (rooms[currentcordX][currentcordY] == 'X')
            {
                cout << "you Have fallen through the floor into a spike trap" << endl;
                isAlive = false;
            }

            rooms[currentcordX][currentcordY] = 'P';
        }
        if (direction == 4)
        {
            rooms[currentcordX][currentcordY] = 'X';
            currentcordY = currentcordY - 1;
            if (rooms[currentcordX][currentcordY] == 'X')
            {
                cout << "you Have fallen through the floor into a spike trap" << endl;
                isAlive = false;
            }
            rooms[currentcordX][currentcordY] = 'P';
        }
        if (rooms[swordx][swordy] == 'P')
        {
            if (hasSword == false)
            {
                hasSword = true;
                cout << "you have found the sword now you can kill the dragon" << endl;
            }
        }
        if (rooms[dragonx][dragony] == 'P' && hasSword == false)
        {
            isAlive = false;
            cout << "you have died" << endl;
        }

        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                cout << rooms[i][j] << "  ";
            }
            cout << endl
                 << endl;
        }
        cout << "Key:" << endl
             << "P=You(as a character)" << endl
             << "E=Exit" << endl
             << "X=Dragon" << endl
             << "K=Key" << endl;
        cout << "Objectives:" << endl
             << " MAIN QUEST" << endl
             << "    -Find Key" << endl
             << "    -Get to exit" << endl
             << " SIDE QUEST" << endl
             << "    -Find Sword" << endl
             << "    -Kill the dragon" << endl;

        if (rooms[dragonx][dragony] == 'P' && hasSword == false)
        {
            cout << "you die" << endl;
            isAlive = false;
        }
        else if (rooms[dragonx][dragony] == 'P' && hasSword == true)
        {
            cout << "the dragon was slain and has thrown the key across the room" << endl;
            dragonAlive = false;
            while (rooms[keyx][keyy] == 'X')
            {
                keyx = rand() % 10;
                keyy = rand() % 10;
            }
            rooms[keyx][keyy] = 'K';
        }
        if (rooms[keyx][keyy] == 'P' && dragonAlive == false)
        {
            if (hasKey == false)
            {
                hasKey = true;
                cout << "you have found the key, now you make make your way to the exit" << endl
                     << endl;
            }
        }
        cout << "Current x=" << currentcordX << " current y=" << currentcordY << endl;
    }
    cout << "you did it!";

    return 0;
}