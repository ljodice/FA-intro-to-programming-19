#include <iostream>
#include <math.h>
#include <ctime>
using namespace std;

struct Song
{
    string name;
    int length;
    bool isEmpty;
};
int main()
{
    string songname;
    int choice, songdel;
    Song playlist[10];
    int size = 0;
    for (int i = 0; i < 10; i++)
    {
        playlist[i].isEmpty = true;
    }
    
    do
    {
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl
             << "what would you like to do?" << endl
             << "1.)play the playlist" << endl
             << "2.)print summary" << endl
             << "3.)add to the playlist" << endl
             << "4.)delete from the playlist" << endl
             << "5.)organize List of songs" << endl
             << "6.)quit";
        cin >> choice;
            cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
        if (choice == 1)
        {
            //play the playlist(print the names of the songs in the playlist
            for (int j = 0; j < 10; j++)
            {
                if (playlist[j].isEmpty)
                {
                    cout << "--EMPTY--" << endl;
                }
                else
                {
                    cout << playlist[j].name << endl;
                }
            }
        }
        else if (choice == 2)
        {
            //print summary(print a summary to the screen saying how many songs as well as the total length of time of all the songs)
            int songnum = 0;
            int songlen = 0;
            for (int j = 0; j < 10; j++)
            {
                if (playlist[j].isEmpty == false)
                {
                    songnum++;
                    songlen = songlen + playlist[j].length;
                }
            }
            int songremsec = songlen % 60;
            int songmin = songlen / 60;
            int songremmin = songmin % 60;
            int songhour = songmin / 60;

            cout << "there are a total of " << songnum << "/10 songs on this playlist" << endl;
            cout << "the total length of the playlist is " << songhour << ":" << songremmin << ":" << songremsec << " seconds long" << endl;
        }
        else if (choice == 3)
        {
            int fullsong;
            int playlistnum = 0;
            //add to te playlist(can hold 10 songs tell user the max) scroll through to find open slot
            for (int j = 0; j < 10; j++)
            {
                if (playlist[j].isEmpty)
                {
                    cout << "what is the name of the song#" << j + 1 << "?indicate that there is a space by putting the character(-)" << endl;
                    cin >> playlist[j].name;
                    cout << "what is the length of the song(in seconds)?" << endl;
                    cin >> playlist[j].length;
                    playlist[j].isEmpty = false;
                }

                else
                {
                    playlistnum++;
                }
                if (playlistnum == 10)
                {
                    cout << "The playlist is full" << endl;
                }
            }
        }
        else if (choice == 4)
        {
            //delete from the playlist(if empty tell tell the user)have user tell you what the song name is that you want to delete
            //best thing to do is change isEmpty=true to isEmpty=true

            cout << "which song would you like to delete from the playlist?" << endl;
            for (int j = 0; j < 10; j++)
            {
                if (playlist[j].isEmpty)
                {
                    cout << "--EMPTY--" << endl;
                }
                else
                {
                    cout << playlist[j].name << endl;
                }
            }

            cin >> songname;
            for (int j = 0; j < 10; j++)
            {
                if (playlist[j].name == songname)
                {
                    playlist[j].isEmpty = true;
                    break;
                }
                else if (j == 9 && playlist[j].name != songname)
                {
                    cout << "there is not a song with that name";
                }
            }
        }
        //organize the song by either alphabetical or by length of song option is up to user
        if (choice == 5)
        {
            cout << "How would you like to organize the songs?" << endl
                 << "1.)Alphibetical" << endl
                 << "2.)Length of song" << endl;
            int orgnum;
            Song orglist[10];
            cin >> orgnum;
            if (orgnum == 1)
            {
                //alphabetical
                //for loop
                //for loop inside
            }
            else if (orgnum == 2)
            {
                //length
                //for loop
                //for loop inside
                /*
                for (int j = 9; i < 0; i--)
                {
                    for (int i = 0; i < 10; i++)
                    {
                        int nosong = 0;
                        int longsong = nosong;
                        string longsongname;
                        if (!playlist[i].isEmpty&&playlist[i].length > longsong)
                        {
                            longsong = playlist[i].length;
                            longsongname = playlist[i].name;
                            playlist[i].isEmpty=true;
                            orglist[0]=playlist[i];
                            break;
                        }
                    }
                }
                */
            }
        }

        if (choice == 6)
        {
            //exit
            cout << "thanks for using the playlist!!";
        }

    } while (choice != 6);
}