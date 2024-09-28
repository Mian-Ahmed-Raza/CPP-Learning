#include <iostream>

const int GRID_SIZE = 3;
const char EMPTY = '-';
const char PLAYER_X = 'X';
const char PLAYER_O = 'O';

int main() {
    char grid[GRID_SIZE][GRID_SIZE];
    int row, col;
    char currentPlayer = PLAYER_X;
    bool gameOver = false;

    // Initialize grid
    for (int i = 0; i < GRID_SIZE; ++i) {
        for (int j = 0; j < GRID_SIZE; ++j) {
            grid[i][j] = EMPTY;
        }
    }

    // Game loop
    do {
        // Display grid
        for (int i = 0; i < GRID_SIZE; ++i) {
            for (int j = 0; j < GRID_SIZE; ++j) {
                std::cout << grid[i][j] << ' ';
            }
            std::cout << std::endl;
        }

        // Get user input
        std::cout << "Player " << currentPlayer << ", enter row and column (0-2): ";
        std::cin >> row >> col;

        // Place mark
        if (row >= 0 && row < GRID_SIZE && col >= 0 && col < GRID_SIZE && grid[row][col] == EMPTY) {
            grid[row][col] = currentPlayer;

            // Check for win
            bool win = false;
            // Check rows and columns
            for (int i = 0; i < GRID_SIZE; ++i) {
                if (grid[i][0] == currentPlayer && grid[i][1] == currentPlayer && grid[i][2] == currentPlayer) {
                    win = true; // Row win
                }
                if (grid[0][i] == currentPlayer && grid[1][i] == currentPlayer && grid[2][i] == currentPlayer) {
                    win = true; // Column win
                }
            }
            // Check diagonals
            if (grid[0][0] == currentPlayer && grid[1][1] == currentPlayer && grid[2][2] == currentPlayer) {
                win = true; // Diagonal win
            }
            if (grid[0][2] == currentPlayer && grid[1][1] == currentPlayer && grid[2][0] == currentPlayer) {
                win = true; // Diagonal win
            }

            if (win) {
                std::cout << "Player " << currentPlayer << " wins!" << std::endl;
                gameOver = true;
            } else {
                // Check for tie
                bool full = true;
                for (int i = 0; i < GRID_SIZE; ++i) {
                    for (int j = 0; j < GRID_SIZE; ++j) {
                        if (grid[i][j] == EMPTY) {
                            full = false;
                            break;
                        }
                    }
                    if (!full) {
                        break;
                    }
                }
                if (full) {
                    std::cout << "It's a tie!" << std::endl;
                    gameOver = true;
                } else {
                    // Switch players
                    currentPlayer = (currentPlayer == PLAYER_X) ? PLAYER_O : PLAYER_X;
                }
            }
        } else {
            std::cout << "Invalid move. Try again." << std::endl;
        }
    } while (!gameOver);

    std::cout << "Thanks for playing Tic-Tac-Toe!" << std::endl;

    return 0;
}
