#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <array>
using namespace std;
int main()
{
    string playerhits[10][10] = {};
    string comhits[10][10] = {};
    
    int playershipmap[10][10] = 
    {
        0,0,0,0,0,0,0,0,0,0,
        0,2,0,3,0,4,0,5,0,0,
        0,2,0,3,0,4,0,5,0,0,
        0,0,0,3,0,4,0,5,0,0,
        0,0,0,0,0,4,0,5,0,0,
        0,0,0,0,0,0,0,5,0,0,
        0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0
    };
    
    int comshipmap[10][10] = 
    {
        0,0,0,0,0,0,0,0,0,0,
        0,2,0,3,0,4,0,5,0,0,
        0,2,0,3,0,4,0,5,0,0,
        0,0,0,3,0,4,0,5,0,0,
        0,0,0,0,0,4,0,5,0,0,
        0,0,0,0,0,0,0,5,0,0,
        0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0
    };
    
    for (int r = 0; r < 10; r++)
    {
        for (int c = 0; c < 10; c++)
        {
            playerhits[r][c] = "~";
        }
    }
    
    for (int r = 0; r < 10; r++)
    {
        for (int c = 0; c < 10; c++)
        {
            comhits[r][c] = "~";
        }
    }


    int comships = 1;
    int pships = 1;
    int ship2 = 2;
    int ship3 = 3;
    int ship4 = 4;
    int ship5 = 5;
    while(comships > 0 && pships > 0)
    {
        cout << "   1 2 3 4 5 6 7 8 9 10" << endl;
        cout << "  +--------------------+" << endl;
        for (int r = 0; r < 10; r++)
        {
            if (r + 1 < 10)
            {
                cout << " " << r + 1 << "| ";
            }
            else
            {
            cout << r + 1 << "| ";
            }
            for (int c = 0; c < 10; c++)
            {
                cout << playerhits[r][c] << " ";
            }
            cout << "|" << endl;
        }
        cout << "  +---------------------+" << endl;
        cout << endl << endl << endl;
        cout << "   1 2 3 4 5 6 7 8 9 10" << endl;
        cout << "  +---------------------+" << endl;
        for (int r = 0; r < 10; r++)
        {
            if (r + 1 < 10)
            {
                cout << " " << r + 1 << "| ";
            }
            else
            {
            cout << r + 1 << "| ";
            }
            for (int c = 0; c < 10; c++)
            {
                cout << playershipmap[r][c] << " ";
            }
            cout <<"|" << endl;
        }
        cout << "  +---------------------+" << endl;
        int phitx;
        int phity;
        cout << "Enter X coordinate to hit (1-9): ";
            cin >> phitx;
        cout << "Enter Y coordinate to hit (1-9): ";
            cin >> phity;
        phitx -= 1;
        phity -= 1;
        if (comshipmap[phity][phitx] > 0)
        {
            cout << "You hit a ship!" << endl;
            playerhits[phity][phitx] = "X";
            comshipmap[phity][phitx] = 0;
            if (comshipmap[phity][phitx] == 2)
            {
                ship2 -= 1;
                if (ship2 == 0)
                {
                    cout << "You sunk a ship" << endl;
                }
            }
            else if (comshipmap[phity][phitx] == 3)
            {
                ship3 -= 1;
                if (ship3 == 0)
                {
                    cout << "You sunk a ship" << endl;
                }
            }
            else if (comshipmap[phity][phitx] == 4)
            {
                ship4 -= 1;
                if (ship4 == 0)
                {
                    cout << "You sunk a ship" << endl;
                }
            }
            else if (comshipmap[phity][phitx] == 5)
            {
                ship5 -= 1;
                if (ship5 == 0)
                {
                    cout << "You sunk a ship" << endl;
                }
            }

        }
        else
        {
            cout << "You missed!" << endl;
            playerhits[phity][phitx] = "O";
        }
        cout << "Computer's turn to hit." << endl;
        srand(time(0));
        int chitx = rand() % 10;
        int chity = rand() % 10;
        if (playershipmap[chity][chitx] > 0)
        {
            cout << "Computer hit your ship at (" << chitx + 1 << ", " << chity + 1 << ")!" << endl;
            comhits[chity][chitx] = "X";
            playershipmap[chity][chitx] = 0;
        }

        for (int r = 0; r < 10; r++)
        {
            for (int c = 0; c < 10; c++)
            {
               pships += playershipmap[r][c];
            }
            cout << endl;
        }

        for (int r = 0; r < 10; r++)
        {
            for (int c = 0; c < 10; c++)
            {
               comships += comshipmap[r][c];
            }
            cout << endl;
        }
        system("clear");

    }
    if (comships == 0)
    {
        cout << "You win!" << endl;
    }
    else
    {
        cout << "Computer wins!" << endl;
    }
    return 0;
}

        
