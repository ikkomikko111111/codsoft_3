
#include <iostream>
using namespace std;

char board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
char currentPlayer = 'X';

void displayBoard() {
    cout << "Current board: \n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}
bool isWin() {
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) || 
            (board[0][i] == board[1][i] && board[1][i] == board[2][i])) {
            return true;
        }
    } 
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0])) {
        return true;
    }
    return false;
}
bool isDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false; 
            }
        }
    }
    return true;
}
void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}
void makeMove() {
    int move;
    cout << "Player " << currentPlayer << ", enter your move (1-9): ";
    cin >> move;

    bool validMove = false;
    for (int i = 0; i < 3 && !validMove; i++) {
        for (int j = 0; j < 3 && !validMove; j++) {
            if (board[i][j] == move + '0') {
                board[i][j] = currentPlayer;
                validMove = true;
            }
        }
    }
    if (!validMove) {
        cout << "Invalid move! Try again.\n";
        makeMove();
    }
}
void playGame() {
    bool gameWon = false, gameDraw = false;
    
    while (!gameWon && !gameDraw) {
        displayBoard();
        makeMove();
        gameWon = isWin();
        gameDraw = isDraw();

        if (!gameWon && !gameDraw) {
            switchPlayer();
        }
    }

    displayBoard();  
    if (gameWon) {
        cout << "Player " << currentPlayer << " wins!" << endl;
    } else if (gameDraw) {
        cout << "The game is a draw!" << endl;
    }
}
int main() {
    char playAgain = 'y';

    while (playAgain == 'y' || playAgain == 'Y') {
        char initialBoard[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board[i][j] = initialBoard[i][j];
            }
        }
        currentPlayer = 'X';  

        playGame();

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    }
    cout << "Thank you for playing!" << endl;5
    
    return 0;
}
