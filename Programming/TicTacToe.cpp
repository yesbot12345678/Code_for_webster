#include <iostream>
#include <ctime>
using namespace std;

void makeboard(char *spaces);
void pmove(char *spaces, char player);
void cmove(char *spaces, char computer);
bool checkwin(char *spaces, char player, char computer);
bool checktie(char *spaces);

int main() 
{
    char spaces[9] = {};
    fill(begin(spaces), end(spaces), ' ');
    char player = 'X';
    char computer = 'O';
    bool gameover = false;

    makeboard(spaces);
    while (!gameover)
    {
        
        pmove(spaces, player);
        makeboard(spaces);
        system("clear");
        cmove(spaces, computer);
        makeboard(spaces);
        if(checkwin(spaces, player, computer))
        {
            gameover = true;
            break;
        }
        else if(checktie(spaces))
        {
            gameover = true;
            break;
        }

    }
    cout << "Game Over\n";
    return 0;
}

void makeboard(char *spaces)
{
    cout << " " << spaces[0] << " | " << spaces[1] << " | " << spaces[2] << " \n";
    cout << "---|---|---\n";
    cout << " " << spaces[3] << " | " << spaces[4] << " | " << spaces[5] << " \n";
    cout << "---|---|---\n";
    cout << " " << spaces[6] << " | " << spaces[7] << " | " << spaces[8] << " \n";
    cout << endl;
}
void pmove(char *spaces, char player)
{
    int num;
    do
    {
        cout << "Enter a number 1-9 to place your X: ";
        cin >> num;
        num --;
        if(spaces[num] == ' ')
        {
            spaces[num] = player;
            break;
        }
        else
        {
            cout << "That space is already occupied. Try again.\n";
        }

    } while (!num > 0 || !num < 8 );

}
void cmove(char *spaces, char computer)
{
    int num;
    srand(time(0));
    while(true)
    {
        start:
        num = rand() % 9;
        if(spaces[num] == ' ')
        {
            spaces[num] = computer;
            break;
        }
        else
        {
            goto start;
        }
    }
}
bool checkwin(char *spaces, char player, char computer)
{
    if(spaces[0] != ' ' && spaces[0] == spaces[1] && spaces[1] == spaces[2])
    {
        if(spaces[0] == player )
        {
            cout << "you win\n";
        }
        else
        {
            cout << "computer wins\n";
        }    
    }
    else if(spaces[3] != ' ' && spaces[3] == spaces[4] && spaces[4] == spaces[5])
    {
        if(spaces[3] == player )
        {
            cout << "you win\n";
        }
        else
        {
            cout << "computer wins\n";
        }    
    }
    else if(spaces[6] != ' ' && spaces[6] == spaces[7] && spaces[7] == spaces[8])
    {
        if(spaces[6] == player )
        {
            cout << "you win\n";
        }
        else
        {
            cout << "computer wins\n";
        }    
    }
    else if(spaces[0] != ' ' && spaces[0] == spaces[3] && spaces[3] == spaces[6])
    {
        if(spaces[0] == player )
        {
            cout << "you win\n";
        }
        else
        {
            cout << "computer wins\n";
        }    
    }
    else if(spaces[1] != ' ' && spaces[1] == spaces[4] && spaces[4] == spaces[7])
    {
        if(spaces[1] == player )
        {
            cout << "you win\n";
        }
        else
        {
            cout << "computer wins\n";
        }   
    }
    else if(spaces[2] != ' ' && spaces[2] == spaces[5] && spaces[5] == spaces[8])
    {
        if(spaces[2] == player )
        {
            cout << "you win\n";
        }
        else
        {
            cout << "computer wins\n";
        }    
    }
    else if(spaces[0] != ' ' && spaces[0] == spaces[4] && spaces[4] == spaces[8])
    {
        if(spaces[0] == player )
        {
            cout << "you win\n";
        }
        else
        {
            cout << "computer wins\n";
        }    
    }
    else if(spaces[2] != ' ' && spaces[2] == spaces[4] && spaces[4] == spaces[6])
    {   
        if(spaces[2] == player )
        {
            cout << "you win\n";
        }
        else
        {
            cout << "computer wins\n";
        }

    }
    else
    {
        return false;
    }
    return true;
}
bool checktie(char *spaces)
{
    for(int i = 0; i < 9; i++)
    {
        if(spaces[i] == ' ')
        {
            return false;
        }
    }
    cout << "tie game\n";
    return true;
}