#include<iostream>
#include<vector>
#include<string>

using namespace std;

void displayBoard(const vector<string>& chessBoard);
void initalizeBoard(vector<string>& chessBoard);
void player1Move();
void player2Move();

int main()
{
    vector<string> chessBoard(8, string(8, '.'));
    initalizeBoard(chessBoard);
    displayBoard(chessBoard);


    return 0;
}

void displayBoard(const vector<string>& chessBoard) {
    cout << "   1 2 3 4 5 6 7 8\n";
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
void player1Move() {
    string move;
    cout << "Player 1, enter your move(format: e2 e4): "; 
    getline(cin, move);
    string letterFrom = move.substr(0,1);
    string letterTo = move.substr(3,1);


}
void player2Move() {
    
}