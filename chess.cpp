#include<iostream>
#include<vector>
#include<string>
#include<limits>

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
        system("clear");
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
    int done = 0;
    while (done == 0){

        cout << "Player 1, enter your move(format: e2 e4): "; 
        getline(cin, move);

        if (move.length() != 5 || move[2] != ' ') {
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
        if (LetterFrom < 0 || LetterTo < 0) {
            cout << "you did not enter a valid move\n";
            continue;
        }
        char fromPiece = chessBoard[numberFrom][LetterFrom];
        char toPiece = chessBoard[numberTo][LetterTo];
        bool fromIsWhite = (fromPiece >= 'A' && fromPiece <= 'Z');
        bool toIsWhite = (toPiece >= 'A' && toPiece <= 'Z');

        if (fromPiece == '.') {
            cout << "there is no piece there\n";
            continue;
        }
        if (!fromIsWhite) {
            cout << "you cannot move opponent's piece\n";
            continue;
        }
        if (toIsWhite) {
            cout << "you cannot capture your own piece\n";
            continue;
        }

        if (Whitecheck(chessBoard)){
            cout << "Player 1, you are in check!\n";
            if (chessBoard[numberFrom][LetterFrom] != 'K'){
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
            if ((chessBoard[numberTo][LetterTo] == 'P') && (numberTo == 0 || numberTo == 7)){
                cout << "Player 1 promote to (Q Or N): ";
                char promoteTo;
                cin >> promoteTo;
                chessBoard[numberTo][LetterTo] = promoteTo;
            }
            done = 1;
        }
        else{
                cout << "you did not enter a valid move\n";
                continue;
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

        if (move.length() != 5 || move[2] != ' ') {
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
        if (LetterFrom < 0 || LetterTo < 0) {
            cout << "you did not enter a valid move\n";
            continue;
        }
        char fromPiece = chessBoard[numberFrom][LetterFrom];
        char toPiece = chessBoard[numberTo][LetterTo];
        bool fromIsBlack = (fromPiece >= 'a' && fromPiece <= 'z');
        bool toIsBlack = (toPiece >= 'a' && toPiece <= 'z');

        if (fromPiece == '.') {
            cout << "there is no piece there\n";
            continue;
        }
        if (!fromIsBlack) {
            cout << "you cannot move opponent's piece\n";
            continue;
        }
        if (toIsBlack) {
            cout << "you cannot capture your own piece\n";
            continue;
        }

        if (Blackcheck(chessBoard)){
            cout << "Player 2, you are in check!\n";
            if (chessBoard[numberFrom][LetterFrom] != 'k'){
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
            if ((chessBoard[numberTo][LetterTo] == 'p') && (numberTo == 0 || numberTo == 7)){
                cout << "Player 2 promote to (Q Or N): ";
                char promoteTo;
                cin >> promoteTo;
                chessBoard[numberTo][LetterTo] = promoteTo;
            }
            done = 1;
        }
        else{
            cout << "you did not enter a valid move\n";
            continue;
        }
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
                for (int i = numberFrom + 1; i < numberTo; i++) {
                    if (chessBoard[i][letterFrom] != '.') {
                        return false; 
                    }
                }
                return true;
            }
            else if (numberFrom > numberTo && letterFrom == letterTo){ // down
                for (int i = numberFrom - 1; i > numberTo; i--) {
                    if (chessBoard[i][letterFrom] != '.') {
                        return false; 
                    }
                }
                return true;
            }
            else if (letterFrom < letterTo && numberFrom == numberTo){ // right
                for (int j = letterFrom + 1; j < letterTo; j++) {
                    if (chessBoard[numberFrom][j] != '.') {
                        return false; 
                    }
                }
                return true;
            }
            else if (letterFrom > letterTo && numberFrom == numberTo){ // left
                for (int j = letterFrom - 1; j > letterTo; j--) {
                    if (chessBoard[numberFrom][j] != '.') {
                        return false; 
                    }
                }
                return true;
            }
            else {
                return false;
            }
        }
        if (chessBoard[numberFrom][letterFrom]== 'n' || chessBoard[numberFrom][letterFrom]== 'N' ){
            if (numberFrom + 2 == numberTo && letterFrom - 1 == letterTo){ // up left
                return true;
            }
            else if (numberFrom + 2 == numberTo && letterFrom + 1 == letterTo){ // up right
                return true;
            }
            else if (numberFrom + 1 == numberTo && letterFrom + 2 == letterTo){ // right up
                return true;
            }
            else if (numberFrom - 1 == numberTo && letterFrom + 2 == letterTo){ // right down
                return true;
            }
            else if (numberFrom - 2 == numberTo && letterFrom + 1 == letterTo){ // down right
                return true;
            }
            else if (numberFrom - 2 == numberTo && letterFrom - 1 == letterTo){ // down left
                return true;
            }
            else if (numberFrom + 1 == numberTo && letterFrom - 2 == letterTo){ // left up
                return true;
            }
            else if (numberFrom - 1 == numberTo && letterFrom - 2 == letterTo){ // left down
                return true;
            }
            else {
                return false;
            }
        }
        if (chessBoard[numberFrom][letterFrom]== 'b' || chessBoard[numberFrom][letterFrom]== 'B' ){
            if (numberFrom < numberTo && letterFrom > letterTo){ // up left
                int i = numberFrom + 1, j = letterFrom - 1;
                while (i < numberTo && j >= 0) {
                    if (chessBoard[i][j] != '.') {
                        return false; 
                    }
                    i++; j--;
                }
                if (i == numberTo && j == letterTo) return true;
                return false;
            }
            else if (numberFrom > numberTo && letterFrom > letterTo){ // down left
                int i = numberFrom - 1, j = letterFrom - 1;
                while (i > numberTo && j >= 0) {
                    if (chessBoard[i][j] != '.') {
                        return false; 
                    }
                    i--; j--;
                }
                if (i == numberTo && j == letterTo) return true;
                return false;
            }
            else if (numberFrom > numberTo && letterFrom < letterTo){ // down right
                int i = numberFrom - 1, j = letterFrom + 1;
                while (i > numberTo && j < 8) {
                    if (chessBoard[i][j] != '.') {
                        return false; 
                    }
                    i--; j++;
                }
                if (i == numberTo && j == letterTo) return true;
                return false;
            }
            else if (numberFrom < numberTo && letterFrom < letterTo){ // up right
                int i = numberFrom + 1, j = letterFrom + 1;
                while (i < numberTo && j < 8) {
                    if (chessBoard[i][j] != '.') {
                        return false; 
                    }
                    i++; j++;
                }
                if (i == numberTo && j == letterTo) return true;
                return false;
            }
            else {
                return false;
            }
        }
        if (chessBoard[numberFrom][letterFrom]== 'q' || chessBoard[numberFrom][letterFrom]== 'Q' ){
            if (numberFrom < numberTo && letterFrom == letterTo){ // up
                for (int i = numberFrom + 1; i < numberTo; i++) {
                    if (chessBoard[i][letterFrom] != '.') {
                        return false; 
                    }
                }
                return true;
            }
            else if (numberFrom > numberTo && letterFrom == letterTo){ // down
                for (int i = numberFrom - 1; i > numberTo; i--) {
                    if (chessBoard[i][letterFrom] != '.') {
                        return false; 
                    }
                }
                return true;
            }
            else if (numberFrom == numberTo && letterFrom < letterTo){ // right
                for (int j = letterFrom + 1; j < letterTo; j++) {
                    if (chessBoard[numberFrom][j] != '.') {
                        return false; 
                    }
                }
                return true;
            }
            else if (numberFrom == numberTo && letterFrom > letterTo){ // left
                for (int j = letterFrom - 1; j > letterTo; j--) {
                    if (chessBoard[numberFrom][j] != '.') {
                        return false; 
                    }
                }
                return true;
            }
            else if (numberFrom < numberTo && letterFrom > letterTo){ // up left
                int i = numberFrom + 1, j = letterFrom - 1;
                while (i < numberTo && j >= 0) {
                    if (chessBoard[i][j] != '.') {
                        return false; 
                    }
                    i++; j--;
                }
                if (i == numberTo && j == letterTo) return true;
                return false;
            }
            else if (numberFrom > numberTo && letterFrom > letterTo){ // down left
                int i = numberFrom - 1, j = letterFrom - 1;
                while (i > numberTo && j >= 0) {
                    if (chessBoard[i][j] != '.') {
                        return false; 
                    }
                    i--; j--;
                }
                if (i == numberTo && j == letterTo) return true;
                return false;
            }
            else if (numberFrom > numberTo && letterFrom < letterTo){ // down right
                int i = numberFrom - 1, j = letterFrom + 1;
                while (i > numberTo && j < 8) {
                    if (chessBoard[i][j] != '.') {
                        return false; 
                    }
                    i--; j++;
                }
                if (i == numberTo && j == letterTo) return true;
                return false;
            }
            else if (numberFrom < numberTo && letterFrom < letterTo){ // up right
                int i = numberFrom + 1, j = letterFrom + 1;
                while (i < numberTo && j < 8) {
                    if (chessBoard[i][j] != '.') {
                        return false; 
                    }
                    i++; j++;
                }
                if (i == numberTo && j == letterTo) return true;
                return false;
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
            if (numberFrom + 2 == numberTo && letterFrom == letterTo && numberFrom == 1 && numberTo < 8 && chessBoard[numberFrom + 2][letterFrom] == '.'){ // up two
                return true;
            }
            if (numberFrom + 1 == numberTo && letterFrom == letterTo && numberTo < 8 && chessBoard[numberFrom + 1][letterFrom] == '.'){ // up
                return true;
            }
            else if (numberFrom + 1 == numberTo && letterFrom + 1 == letterTo && numberTo < 8 && letterFrom + 1 < 8 && chessBoard[numberFrom + 1][letterFrom + 1] != '.'){ // up right - only if piece there
                return true;
            }
            else if (numberFrom + 1 == numberTo && letterFrom - 1 == letterTo && numberTo < 8 && letterFrom - 1 >= 0 && chessBoard[numberFrom + 1][letterFrom - 1] != '.'){ // up left - only if piece there
                return true;
            }
            else if (numberFrom + 1 == numberTo && letterFrom + 1 == letterTo && numberTo < 8 && letterFrom + 1 < 8 && chessBoard[numberFrom][letterFrom + 1] == 'P' && numberFrom == 4){ // en passant
                return true;
            }
            else if (numberFrom + 1 == numberTo && letterFrom - 1 == letterTo && numberTo < 8 && letterFrom - 1 >= 0 && chessBoard[numberFrom][letterFrom - 1] == 'P' && numberFrom == 4){ // en passant
                return true;
            }
            else {
                return false;
            }
        }
        if (chessBoard[numberFrom][letterFrom]== 'P' ){
            if (numberFrom - 2 == numberTo && letterFrom == letterTo && numberFrom == 6 && numberTo >= 0 && chessBoard[numberFrom - 2][letterFrom] == '.'){ // down two
                return true;
            }
            else if (numberFrom - 1 == numberTo && letterFrom == letterTo && numberTo >= 0 && chessBoard[numberFrom - 1][letterFrom] == '.'){ // down
                return true;
            }
            else if (numberFrom - 1 == numberTo && letterFrom + 1 == letterTo && numberTo >= 0 && letterFrom + 1 < 8 && chessBoard[numberFrom - 1][letterFrom + 1] != '.'){ // down right - only if piece there
                return true;
            }
            else if (numberFrom - 1 == numberTo && letterFrom - 1 == letterTo && numberTo >= 0 && letterFrom - 1 >= 0 && chessBoard[numberFrom - 1][letterFrom - 1] != '.'){ // down left - only if piece there
                return true;
            }
            else if (numberFrom - 1 == numberTo && letterFrom + 1 == letterTo && numberTo >= 0 && letterFrom + 1 < 8 && chessBoard[numberFrom][letterFrom + 1] == 'p' && numberFrom == 5){ // en passant
                return true;
            }
            else if (numberFrom - 1 == numberTo && letterFrom - 1 == letterTo && numberTo >= 0 && letterFrom - 1 >= 0 && chessBoard[numberFrom][letterFrom - 1] == 'p' && numberFrom == 5){ // en passant
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
bool Whitecheck(vector<string>& chessBoard){
    int WhitekingLetter = 0;
    int WhitekingNumber = 0;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if (chessBoard[i][j] == 'K'){
                WhitekingLetter = j;
                WhitekingNumber = i;
            }
        }
    }
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            char piece = chessBoard[i][j];
            if (piece == 'r' || piece == 'n' || piece == 'b' || piece == 'q' || piece == 'p'){
                if (legalMove(chessBoard, j, WhitekingLetter, i, WhitekingNumber)){
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
            if (chessBoard[i][j] == 'k'){
                BlackkingLetter = j;
                BlackkingNumber = i;
            }
        }
    }
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            char piece = chessBoard[i][j];
            if (piece == 'R' || piece == 'N' || piece == 'B' || piece == 'Q' || piece == 'P'){
                if (legalMove(chessBoard, j, BlackkingLetter, i, BlackkingNumber)){
                    return true;
                }
            }
        }
    }
    return false;
}
