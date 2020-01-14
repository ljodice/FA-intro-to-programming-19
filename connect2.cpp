#include <iostream>
using namespace std;

void clear(int grid[4][4])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            grid[i][j] = 0;
        }
    }
}

void print(int grid[4][4])
{
    cout << "Here's what the game looks like now:\n";
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << grid[i][j] << "  ";
        }
        cout << endl;
    }
}
bool dropcheck(int grid[4][4], int dropcol)
{
    int validcol = 0;
    for (int i = 3; i >= 0; i--)
    {
        if (grid[i][dropcol] == 0)
        {
            validcol++;
        }
    }
    if (validcol > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void drop(int grid[4][4], int player, int coulmnent)
{
    int spots;
    int droploc = coulmnent - 1;
    for (int i = 3; i >= 0; i--)
    {
        if (grid[i][droploc] == 0)
        {
            grid[i][droploc] = player;
            print(grid);
            break;
        }
    }
}

bool winner(int grid[4][4], int player)
{
    int counter;
    //horizontal
    for (int row = 0; row < 4; row++)
    {
        counter = 0;
        for (int column = 0; column < 4; column++)
        {
            if (grid[row][column] == player)
            {
                counter++;
                if (counter >= 4)
                {
                    return true;
                }
            }
        }
    }
    //vert
    for (int row = 0; row < 4; row++)
    {
        counter = 0;
        for (int column = 0; column < 4; column++)
        {
            if (grid[column][row] == player)
            {
                counter++;
                if (counter >= 4)
                {
                    return true;
                }
            }
        }
    }
    //across
    counter = 0;
    for (int i = 0; i < 4; i++)
    {
        if (grid[i][i] == player)
        {
            counter++;
            if (counter >= 4)
            {
                return true;
            }
        }
    }
    //other across
    //increment the rows up and the col down
    int column = 0;
    for (int row = 3; row >= 0; row--)
    {
        counter = 0;
        if (grid[row][column] == player)
        {
            counter++;
            if (counter >= 4)
            {
                return true;
            }
        }
        column++;
    }
    return false;
}
int main()
{
    int grid[4][4];
    int dropsel, dropsel2;
    int player1 = 1;
    int player2 = 2;
    int winnername = 0;
    bool wincond1 = false;
    bool wincond2 = false;
    clear(grid);
    print(grid);
    int turns = 0;
    do
    {
        //player 1

        do
        {
            if (!dropcheck(grid, dropsel))
            {
                cout << "the drop location was invalid because there is not an open space, pick another one" << endl;
            }
            cout << "Player 1:where do you want to drop?" << endl;
            cin >> dropsel;
            //valid drop check
        } while (!dropcheck(grid, dropsel));
        drop(grid, player1, dropsel);
        //player 2
        if (!winner(grid, player1))
        {
            do
            {
                if (!dropcheck(grid, dropsel2))
                {
                    cout << "the drop location was invalid because there is not an open space, pick another one" << endl;
                }
                cout << "player 2: where do you want to drop" << endl;
                cin >> dropsel2;
            } while (!dropcheck(grid, dropsel2));
            drop(grid, player2, dropsel2);
        }
    } while (!winner(grid, player1) && !winner(grid, player2));
    if(winner(grid, player1)){
        cout<<"the winner was player 1"<<endl;
    }
    if(winner(grid, player2)){
        cout<<"the winner was player 2"<<endl;
    }
    return 0;
}