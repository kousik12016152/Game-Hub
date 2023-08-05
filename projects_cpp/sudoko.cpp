//Recurssive code
//Time Complexity O(81)
//Space Complexity O(81)
#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool safe(vector<vector<char>>& board, int i, int j, char c) {
    for (int k = 0; k < 9; k++) {
        if (board[k][j] == c)
            return false;
        if (board[i][k] == c)
            return false;
        if (board[3 * (i / 3) + k / 3][3 * (j / 3) + k % 3] == c)
            return false;
    }
    return true;
}

bool fun(vector<vector<char>>& board) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            if (board[i][j] == '.') {
                for (char c = '1'; c <= '9'; c++) {
                    if (safe(board, i, j, c)) {
                        board[i][j] = c;
                        if (fun(board))
                            return true;
                        else
                            board[i][j] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}

bool solveSudoku(vector<vector<char>>& board) {
    return fun(board);
}

int main() {
    cout<<"please enter a valid sudoko"<<endl;
    cout<<" enter Enter the 9X9 Sudoku to solve"<<endl;
    cout<<" Enter all the numbers row by row, seperated by spaces. For cells that are empty, enter '.'"<<endl;
    vector<vector<char>> board(9, vector<char>(9));
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> board[i][j];s
        }
    }
    cout<<"This is the Sudoku you have entered."<<endl;
    cout<<"wait patiently"<<endl;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }

    //solveSudoku(board);
    fun(board);
    cout << "Solved Sudoku:" << endl;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
