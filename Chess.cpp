#include<iostream>
#include<vector>
#include<string>

using namespace std;

void displayBoard(const vector<string>& chessBoard);
void initalizeBoard(vector<string>& chessBoard);
void player1Move(vector<string>& chessBoard);
void player2Move(vector<string>& chessBoard);
bool gameOver(vector<string>& chessBoard);
int main()
{
    
    vector<string> chessBoard(8, string(8, '.'));
    initalizeBoard(chessBoard);
    bool gameover = gameOver(chessBoard);
    while (!gameover) {
        displayBoard(chessBoard);
        player1Move(chessBoard);
        displayBoard(chessBoard);
        gameover = gameOver(chessBoard);
        if (!gameover){
            player2Move(chessBoard);
            displayBoard(chessBoard);
            gameOver(chessBoard);
            gameover = gameOver(chessBoard);
        }
        system("clear");
    }

    gameOver(chessBoard);
    return 0;
}

void displayBoard(const vector<string>& chessBoard) {
    cout << "   a b c d e f g h\n";
    cout << " +-----------------+\n";
    for(int i = 0; i < 8; ++i) {
        cout << i + 1 << "| ";
        for(int j = 0; j < 8; ++j) {
            cout << chessBoard[i][j] << " ";
        }
        cout << "|\n";
    }
    cout << " +-----------------+\n";
}
void initalizeBoard(vector<string>& chessBoard) {
    chessBoard[0] = "rnbqkbnr";
    chessBoard[1] = "pppppppp";
    chessBoard[6] = "PPPPPPPP";
    chessBoard[7] = "RNBQKBNR";
}
void player1Move(vector<string>& chessBoard) {
    string move;
    cout << "Player 1, enter your move(format: e2 e4): "; 
    getline(cin, move);
    string letterFrom = move.substr(0,1);
    string letterTo = move.substr(3,1);

    char FROM= move[1];
    char TO= move[4];
    int numberFrom = FROM - '0';
    int numberTo = TO - '0';
    numberFrom -= 1;
    numberTo -= 1;

    int LetterFrom;
    int LetterTo;
    switch (letterFrom[0]) {
        case 'a': 
            LetterFrom = 0;
        break;
        case 'b':
            LetterFrom = 1;
        break;
        case 'c':
            LetterFrom = 2;
        break;
        case 'd':
            LetterFrom = 3;
        break;
        case 'e':
            LetterFrom = 4;
        break;
        case 'f':
            LetterFrom = 5;
        break;
        case 'g':
            LetterFrom = 6;
        break;
        case 'h':
            LetterFrom = 7;
        break;    
    }
    switch(letterTo[0]) {
        case 'a': 
            LetterTo = 0;
        break;
        case 'b':
            LetterTo = 1;
        break;
        case 'c':
            LetterTo = 2;
        break;
        case 'd':
            LetterTo = 3;
        break;
        case 'e':
            LetterTo = 4;
        break;
        case 'f':
            LetterTo = 5;
        break;
        case 'g':
            LetterTo = 6;
        break;
        case 'h':
            LetterTo = 7;
        break;    
    }

    chessBoard[numberTo][LetterTo] = chessBoard[numberFrom][LetterFrom];
    chessBoard[numberFrom][LetterFrom] = '.';
}
void player2Move(vector<string>& chessBoard) {
    string move;
    cout << "Player 2, enter your move(format: e2 e4): "; 
    getline(cin, move);
    string letterFrom = move.substr(0,1);
    string letterTo = move.substr(3,1);

    char FROM= move[1];
    char TO= move[4];
    int numberFrom = FROM - '0';
    int numberTo = TO - '0';
    numberFrom -= 1;
    numberTo -= 1;

    int LetterFrom;
    int LetterTo;
    switch (letterFrom[0]) {
        case 'a': 
            LetterFrom = 0;
        break;
        case 'b':
            LetterFrom = 1;
        break;
        case 'c':
            LetterFrom = 2;
        break;
        case 'd':
            LetterFrom = 3;
        break;
        case 'e':
            LetterFrom = 4;
        break;
        case 'f':
            LetterFrom = 5;
        break;
        case 'g':
            LetterFrom = 6;
        break;
        case 'h':
            LetterFrom = 7;
        break;    
    }
    switch(letterTo[0]) {
        case 'a': 
            LetterTo = 0;
        break;
        case 'b':
            LetterTo = 1;
        break;
        case 'c':
            LetterTo = 2;
        break;
        case 'd':
            LetterTo = 3;
        break;
        case 'e':
            LetterTo = 4;
        break;
        case 'f':
            LetterTo = 5;
        break;
        case 'g':
            LetterTo = 6;
        break;
        case 'h':
            LetterTo = 7;
        break;    
    }

    chessBoard[numberTo][LetterTo] = chessBoard[numberFrom][LetterFrom];
    chessBoard[numberFrom][LetterFrom] = '.';
}
bool gameOver(vector<string>& chessBoard){
    int whiteWin = 0;
    int blackWin = 0;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if (chessBoard[i][j] == 'k'){
                whiteWin = 1;
            }
            if (chessBoard[i][j] == 'K'){
                blackWin = 1;
            }
        }
    }
    if (whiteWin == blackWin){
        return false;
    }
    else if (whiteWin == 0){
        cout << "Player 1 wins!" << endl;
        return true;
    }
    else if (blackWin == 0){
        cout << "Player 2 wins!" << endl;
        return true;
    }
}
void legalMove(vector<string>& chessBoard, int letterFrom, int letterTo, int numberFrom, int numberTo){
    int N = chessBoard[numberFrom + 1][letterFrom];
    int S = chessBoard[numberFrom - 1][letterFrom];
    int W = chessBoard[numberFrom][letterFrom - 1];
    int E = chessBoard[numberFrom][letterFrom +1];
    int NW = chessBoard[numberFrom + 1][ letterFrom - 1];
    int SW = chessBoard[numberFrom - 1][letterFrom - 1];
    int SE = chessBoard[numberFrom - 1][letterFrom + 1];
    int NE = chessBoard[numberFrom + 1][letterFrom + 1];  

    if (chessBoard[numberFrom][letterFrom]== 'r' || chessBoard[numberFrom][letterFrom]== 'R' ){
        if (N != '.'){
            if (numberFrom < numberTo){

            }
        }
        else if (S != '.'){
            if (numberFrom > numberTo){

            }
        }
        else if (E != '.'){
            if (letterFrom < letterTo){

            }
        }
        else if (W != '.'){
            if (letterFrom > letterTo){

            }
        }
    }
    if (chessBoard[numberFrom][letterFrom]== 'n' || chessBoard[numberFrom][letterFrom]== 'N' ){
        
    }
    if (chessBoard[numberFrom][letterFrom]== 'b' || chessBoard[numberFrom][letterFrom]== 'B' ){
        if (NW != '.'){

        }
        else if (SW != '.'){

        }
        else if (SE != '.'){

        }
        else if (NE != '.'){

        }
    }
    if (chessBoard[numberFrom][letterFrom]== 'q' || chessBoard[numberFrom][letterFrom]== 'Q' ){
        if (N != '.'){

        }
        else if (S != '.'){

        }
        else if (E != '.'){

        }
        else if (W != '.'){

        }
        else if (NW != '.'){

        }
        else if (SW != '.'){

        }
        else if (SE != '.'){

        }
        else if (NE != '.'){

        }
    }
    if (chessBoard[numberFrom][letterFrom]== 'k' || chessBoard[numberFrom][letterFrom]== 'K' ){
        if (N != '.'){

        }
        else if (S != '.'){

        }
        else if (E != '.'){

        }
        else if (W != '.'){

        }
        else if (NW != '.'){

        }
        else if (SW != '.'){

        }
        else if (SE != '.'){

        }
        else if (NE != '.'){

        }
    }
    if (chessBoard[numberFrom][letterFrom]== 'p' || chessBoard[numberFrom][letterFrom]== 'P' ){
        if (N != '.'){

        }
        else if (NE != '.'){

        }
        else if (NW != '.'){

        }
    }
}
