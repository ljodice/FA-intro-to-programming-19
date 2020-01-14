#include <iostream>
using namespace std;

void clear(int grid[4][4])
{
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++)
        {
            grid[i][j] = 0;
        }
    }
}

void print(int grid[4][4])
{
    cout << "Here's what the game looks like now:\n";
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++)
        {
            cout << grid[i][j] << "  ";
        }
        cout << endl;
    }
}
void drop(int grid[4][4], int player, int coulmnent){
    int spots;
         int droploc=coulmnent-1;
        for(int i=3; i>=0; i--){
         if(grid[i][droploc]==0){
             grid[i][droploc]=player;
             print(grid);
             spots++;
             if(spots>4){
                 cout<<"you can not move there, because the location was invalid your turn is over"<<endl;
             }
             break;
         }
         }
        

}
bool winner(int grid[4][4], int player){

}
int main()
{
    int grid[4][4];
    int dropsel,dropsel2;
    int player1= 1;
    int player2 = 2;
    int winnername=0;
    bool wincond1 =false;
    bool wincond2=false;
    clear(grid);
    print(grid);
    int turns=0;
    do{        
          int openspace=0;
          cout<<"what location would you,player 1, like to drop the token?"<<endl;
        cin>>dropsel;
       /*
        do{
        for(int i=0; i>4; i++){
            if(grid[i][dropsel]==0){
                openspace++;
            }
        }
        if(openspace=0){
            cout<<"there is not any open spaces"<<endl;
        }
        }while(openspace==0);
         */
         drop(grid, player1, dropsel);
         wincond1=winner(grid, player1);
         if(wincond1){
             winnername=1;
             break;
         }
    turns++;
  
  cout<<"what location would you,player 2, like to drop the token?"<<endl;
        cin>>dropsel2;
        drop(grid, player2, dropsel2);
     /*
      wincond2=winner(grid, player2);
      if(wincond2){
          winnername=2;
      }
      */
       print(grid);
      turns++;
    }
    while(turns<16||(!wincond1||!wincond2));
    

   print(grid);
    return 0;
}