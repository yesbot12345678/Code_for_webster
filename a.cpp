#include<iostream>
#include<vector>
#include<string>

using namespace std;

void displayBoard(const vector<string>& chessBoard);
void initalizeBoard(vector<string>& chessBoard);
bool legalMove(vector<string>& chessBoard, int letterFrom, int letterTo, int numberFrom, int numberTo);
void player1Move(vector<string>& chessBoard);
void player2Move(vector<string>& chessBoard);
bool gameOver(vector<string>& chessBoard);
bool Whitecheck(vector<string>& chessBoard);
bool Blackcheck(vector<string>& chessBoard);
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
    int done = 0;
    while (done == 0){
        cout << "Player 1, enter your move(format: e2 e4): "; 
        getline(cin, move);
        
        if (move.length() < 5) {
            cout << "you did not enter a valid move\n";
            continue;
        }
        
        string letterFrom = move.substr(0,1);
        string letterTo = move.substr(3,1);

        char FROM= move[1];
        char TO= move[4];
        int numberFrom = FROM - '0';
        int numberTo = TO - '0';
        numberFrom -= 1;
        numberTo -= 1;

        if (numberFrom < 0 || numberFrom > 7 || numberTo < 0 || numberTo > 7) {
            cout << "you did not enter a valid move\n";
            continue;
        }

        int LetterFrom = -1;
        int LetterTo = -1;
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
        if (Blackcheck(chessBoard)){
            cout << "Player 1, you are in check!\n";
            if (chessBoard[numberFrom][LetterFrom] != 'K' && chessBoard[numberFrom][LetterFrom] != 'k'){
                cout << "you must move your king out of check\n";
                continue;
            }
            else{
                if (LetterFrom >= 0 && LetterTo >= 0 && legalMove(chessBoard, LetterFrom, LetterTo, numberFrom, numberTo)){
                    chessBoard[numberTo][LetterTo] = chessBoard[numberFrom][LetterFrom];
                    chessBoard[numberFrom][LetterFrom] = '.';
                    done = 1;
                }
                else{
                    cout << "you did not enter a valid move\n";
                    continue;
                }
            }
        }
        else{
        if (LetterFrom >= 0 && LetterTo >= 0 && legalMove(chessBoard, LetterFrom, LetterTo, numberFrom, numberTo)){
            chessBoard[numberTo][LetterTo] = chessBoard[numberFrom][LetterFrom];
            chessBoard[numberFrom][LetterFrom] = '.';
            done = 1;
        }
        else{
                cout << "you did not enter a valid move\n";
                continue;
            }
            if (chessBoard[numberFrom][LetterFrom] == 'P' || chessBoard[numberFrom][LetterFrom] == 'p' && numberTo == 0 || numberTo == 7){
                cout << "Player 1 promote to (Q Or N): ";
                char promoteTo;
                cin >> promoteTo;
                chessBoard[numberTo][LetterTo] = promoteTo;
            }
        }
    }
}
void player2Move(vector<string>& chessBoard) {
    string move;
    int done = 0;
    while (done == 0){
        cout << "Player 2, enter your move(format: e2 e4): "; 
        getline(cin, move);

        if (move.length() < 5) {
            cout << "you did not enter a valid move\n";
            continue;
        }
        
        string letterFrom = move.substr(0,1);
        string letterTo = move.substr(3,1);

        char FROM= move[1];
        char TO= move[4];
        int numberFrom = FROM - '0';
        int numberTo = TO - '0';
        numberFrom -= 1;
        numberTo -= 1;
               
        if (numberFrom < 0 || numberFrom > 7 || numberTo < 0 || numberTo > 7) {
            cout << "you did not enter a valid move\n";
            continue;
        }

        int LetterFrom = -1;
        int LetterTo = -1;
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
        if (LetterFrom >= 0 && LetterTo >= 0 && legalMove(chessBoard, LetterFrom, LetterTo, numberFrom, numberTo)){
            chessBoard[numberTo][LetterTo] = chessBoard[numberFrom][LetterFrom];
            chessBoard[numberFrom][LetterFrom] = '.';
            done = 1;
        }
        else{
            cout << "you did not enter a valid move\n";
            continue;
        }
        if (chessBoard[numberFrom][LetterFrom] == 'P' || chessBoard[numberFrom][LetterFrom] == 'p' && numberTo == 0 || numberTo == 7){
            cout << "Player 2 promote to (Q Or N): ";
            char promoteTo;
            cin >> promoteTo;
            chessBoard[numberTo][LetterTo] = promoteTo;
        }
    }
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
    else{
        return false;
    }
    return false;
}
bool legalMove(vector<string>& chessBoard, int letterFrom, int letterTo, int numberFrom, int numberTo){
    if (numberFrom < 8 && numberTo < 8 && letterFrom < 8 && letterTo <8){
        if (chessBoard[numberFrom][letterFrom]== 'r' || chessBoard[numberFrom][letterFrom]== 'R' ){
            if (numberFrom < numberTo && letterFrom == letterTo){ // up
                return true;
            }
            else if (numberFrom > numberTo && letterFrom == letterTo){ // down
                return true;
            }
            else if (letterFrom < letterTo && numberFrom == numberTo){ // right
                return true;
            }
            else if (letterFrom > letterTo && numberFrom == numberTo){ // left
                return true;
            }
            else {
                return false;
            }
        }
        if (chessBoard[numberFrom][letterFrom]== 'n' || chessBoard[numberFrom][letterFrom]== 'N' ){
            if (numberFrom + 3 == numberTo && letterFrom - 1 == letterTo){ // up left
                return true;
            }
            else if (numberFrom + 3 == numberTo && letterFrom + 1 == letterTo){ // up right
                return true;
            }
            else if (numberFrom + 1 == numberTo && letterFrom + 3 == letterTo){ // right up
                return true;
            }
            else if (numberFrom - 1 == numberTo && letterFrom + 3 == letterTo){ // right down
                return true;
            }
            else if (numberFrom - 3 == numberTo && letterFrom + 1 == letterTo){ // down right
                return true;
            }
            else if (numberFrom - 3 == numberTo && letterFrom - 1 == letterTo){ // down left
                return true;
            }
            else if (numberFrom + 1 == numberTo && letterFrom - 3 == letterTo){ // left up
                return true;
            }
            else if (numberFrom - 1 == numberTo && letterFrom - 3 == letterTo){ // left down
                return true;
            }
            else {
                return false;
            }
        }
        if (chessBoard[numberFrom][letterFrom]== 'b' || chessBoard[numberFrom][letterFrom]== 'B' ){
            if (numberFrom < numberTo && letterFrom > letterTo){ // up left
                return true;
            }
            else if (numberFrom > numberTo && letterFrom > letterTo){ // down left
                return true;
            }
            else if (numberFrom > numberTo && letterFrom < letterTo){ // down right
                return true;
            }
            else if (numberFrom < numberTo && letterFrom < letterTo){ // up right
                return true;
            }
            else {
                return false;
            }
        }
        if (chessBoard[numberFrom][letterFrom]== 'q' || chessBoard[numberFrom][letterFrom]== 'Q' ){
            if (numberFrom < numberTo && letterFrom == letterTo){ // up
                return true;
            }
            else if (numberFrom > numberTo && letterFrom == letterTo){ // down
                return true;
            }
            else if (numberFrom == numberTo && letterFrom < letterTo){ // right
                return true;
            }
            else if (numberFrom == numberTo && letterFrom > letterTo){ // left
                return true;
            }
            else if (numberFrom < numberTo && letterFrom > letterTo){ // up right
                return true;
            }
            else if (numberFrom > numberTo && letterFrom > letterTo){ // down right
                return true;
            }
            else if (numberFrom > numberTo && letterFrom < letterTo){ // down left
                return true;
            }
            else if (numberFrom < numberTo && letterFrom < letterTo){ // up left
                return true;
            }
            else {
                return false;
            }
        }
        if (chessBoard[numberFrom][letterFrom]== 'k' || chessBoard[numberFrom][letterFrom]== 'K' ){
            if (numberFrom + 1 == numberTo && letterFrom == letterTo){ // up
                return true;
            }            
            else if (numberFrom - 1 == numberTo && letterFrom == letterTo){ // down
                return true;
            }
            else if (numberFrom == numberTo && letterFrom + 1 == letterTo){ // right
                return true;
            }
            else if (numberFrom == numberTo && letterFrom - 1 == letterTo){ // left
                return true;
            }
            else if (numberFrom + 1 == numberTo && letterFrom - 1 == letterTo){ // up left
                return true;
            }
            else if (numberFrom - 1 == numberTo && letterFrom - 1 == letterTo){ // down left
                return true;
            }
            else if (numberFrom - 1 == numberTo && letterFrom + 1 == letterTo){ // down right
                return true;
            }
            else if (numberFrom + 1 == numberTo && letterFrom + 1 == letterTo){ // up right
                return true;
            }
            else {
                return false;
            }
        }
        if (chessBoard[numberFrom][letterFrom]== 'p' ){
            if (numberFrom + 2 == numberTo && letterFrom == letterTo && numberFrom == 1 && chessBoard[numberFrom + 2][letterFrom] == '.'){ // up two
                return true;
            }
            if (numberFrom + 1 == numberTo && letterFrom == letterTo && chessBoard[numberFrom + 1][letterFrom] == '.'){ // up
                return true;
            }
            else if (numberFrom + 1 == numberTo && letterFrom + 1 == letterTo && chessBoard[numberFrom + 1][letterFrom + 1] != '.'){ // up right
                return true;
            }
            else if (numberFrom + 1 == numberTo && letterFrom -1 == letterTo && chessBoard[numberFrom + 1][letterFrom - 1] != '.'){ // up left
                return true;
            }
            else {
                return false;
            }
        }
        if (chessBoard[numberFrom][letterFrom]== 'P' ){
            if (numberFrom - 2 == numberTo && letterFrom == letterTo && numberFrom == 6 && chessBoard[numberFrom - 2][letterFrom] == '.'){ // up two
                return true;
            }
            else if (numberFrom - 1 == numberTo && letterFrom == letterTo && chessBoard[numberFrom - 1][letterFrom] != '.'){ // up
                return true;
            }
            else if (numberFrom - 1 == numberTo && letterFrom + 1 == letterTo && chessBoard[numberFrom - 1][letterFrom + 1] != '.'){ // up right
                return true;
            }
            else if (numberFrom - 1 == numberTo && letterFrom -1 == letterTo && chessBoard[numberFrom - 1][letterFrom - 1] != '.'){ // up left
                return true;
            }
            else {
                return false;
            }
        }
    }
    else{
        return false;
    }
    return false;
}

// make not in check for own peices

bool Whitecheck(vector<string>& chessBoard){
    int WhitekingLetter = 0;
    int WhitekingNumber = 0;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if (chessBoard[i][j] == 'k'){
                WhitekingLetter = j;
                WhitekingNumber = i;
            }
        }
    }
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if (legalMove(chessBoard, j, WhitekingLetter, i, WhitekingNumber)){
                if (chessBoard[i][j] != 'r' || chessBoard[i][j] != 'n' || chessBoard[i][j] != 'b' || chessBoard[i][j] != 'q' || chessBoard[i][j] != 'p'){
                    return true;
                }
            }
        }
    }
    return false;
}
bool Blackcheck(vector<string>& chessBoard){
    int BlackkingLetter = 0;
    int BlackkingNumber = 0;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if (chessBoard[i][j] == 'K'){
                BlackkingLetter = j;
                BlackkingNumber = i;
            }
        }
    }
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if (legalMove(chessBoard, j, BlackkingLetter, i, BlackkingNumber)){
                if (chessBoard[i][j] != 'R' || chessBoard[i][j] != 'N' || chessBoard[i][j] != 'B' || chessBoard[i][j] != 'Q' || chessBoard[i][j] != 'P'){
                    return true;
                }
            }
        }
    }
    return false;
}

// make not in check for own peices