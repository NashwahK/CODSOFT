// TASK 3: TIC-TAC-TOE GAME

#include <iostream>
using namespace std;

// Set default value for a player
char playerOne = 'X';

// Create the tic-tac-toe mesh
char mesh[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };

void displaymesh() {
    cout << " " << mesh[0][0] << " | " << mesh[0][1] << " | " << mesh[0][2] << endl;
    cout << "-----------" << endl;
    cout << " " << mesh[1][0] << " | " << mesh[1][1] << " | " << mesh[1][2] << endl;
    cout << "-----------" << endl;
    cout << " " << mesh[2][0] << " | " << mesh[2][1] << " | " << mesh[2][2] << endl;
}

bool checkWin() {
    // Check rows, columns, and diagonals for a win
    for (int i = 0; i < 3; i++) {
        if (mesh[i][0] == playerOne && mesh[i][1] == playerOne && mesh[i][2] == playerOne)
            return true;
        if (mesh[0][i] == playerOne && mesh[1][i] == playerOne && mesh[2][i] == playerOne)
            return true;
    }
    if (mesh[0][0] == playerOne && mesh[1][1] == playerOne && mesh[2][2] == playerOne)
        return true;
    if (mesh[0][2] == playerOne && mesh[1][1] == playerOne && mesh[2][0] == playerOne)
        return true;
    return false;
}

// Check if there is no winner
bool checkDraw() { 
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (mesh[i][j] == ' ')
                return false;
        }
    }
    return true;
}

int main() {
    cout << "\t\tWelcome to Nashwah's Tic-Tac-Toe!" << endl;
    displaymesh();

    while (true) {
        int row, col;
        cout << "Player " << playerOne << ", enter row (0-2):";
        cin >> row;

        cout << "Player " << playerOne << ", enter column(0-2): ";
        cin >> col;

        if (row < 0 || row > 2 || col < 0 || col > 2 || mesh[row][col] != ' ') {
            cout << "Invalid move. Try again." << endl;
            continue;
        }

        mesh[row][col] = playerOne;
        displaymesh();

        if (checkWin()) {
            cout << "Player " << playerOne << " wins!" << endl;
            break;
        } else if (checkDraw()) {
            cout << "It's a draw!" << endl;
            break;
        }

        playerOne = (playerOne == 'X') ? 'O' : 'X';
    }

    cout << "Thank you for playing!" << endl;

    return 0;
}
