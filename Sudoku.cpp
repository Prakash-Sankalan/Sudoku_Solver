//Program to solve a Sudoku
//By Shreyan Prakash
#include<bits/stdc++.h>  
using namespace std;   
const int N = 9;
bool checkvalid(int sudoku[N][N]){
    //Function to check if the Sudoku input by the user follows the rules of Sudoku
    for (int i = 0; i < N; i++) {
        bool rowUsed[N] = {false};
        bool colUsed[N] = {false};
        for (int j = 0; j < N; j++) {
            if (sudoku[i][j] != 0) {
                if (rowUsed[sudoku[i][j] - 1]) {
                    return false; 
                }
                rowUsed[sudoku[i][j] - 1] = true;

            }
            if (sudoku[j][i] != 0) {
                if (colUsed[sudoku[j][i] - 1]) {
                    return false; 
                }
                colUsed[sudoku[j][i] - 1] = true;
            }
        }
    }
    // Check 3x3 subgrids for duplicates
    for (int startRow = 0; startRow < N; startRow += 3) {
        for (int startCol = 0; startCol < N; startCol += 3) {
            bool subgridUsed[N] = {false};
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    int num = sudoku[startRow + i][startCol + j];
                    if (num != 0) {
                        if (subgridUsed[num - 1]) {
                            return false; 
                        }
                        subgridUsed[num - 1] = true;
                    }
                }
            }
        }
    }

    return true; 
}
void display(int sudoku[N][N]){
    //function to display sudoku
 for (int i = 0; i < N; i++) {
        if (i % 3 == 0 && i != 0) {
            cout << "------+-------+------" << endl;
        }
        for (int j = 0; j < N; j++) {
            if (j % 3 == 0 && j != 0) {
                cout << "| ";
            }
            cout << sudoku[i][j] << " ";
        }
        cout << endl;
    }
}
bool fillit(int sudoku[N][N], int row, int col, int num) {
    // function to check if place can be filled
    for (int i = 0; i < N; i++) {
        if (sudoku[row][i] == num || sudoku[i][col] == num) {
            return false;
        }
    }
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (sudoku[startRow + i][startCol + j] == num) {
                return false;
            }
        }
    }
    return true;
}
bool empty(int sudoku[N][N], int& row, int& col) {
    //function to find blank or empty space
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (sudoku[row][col] == 0) {
                return true; 
            }
        }
    }
    return false; 
}
bool solve(int sudoku[N][N]) {
    //function to solve sudoku
    int row, col;

    if (!empty(sudoku, row, col)) {
        return true; 
    }

    for (int num = 1; num <= 9; num++) {
        if (fillit(sudoku, row, col, num)) {
            
            sudoku[row][col] = num;
            
            if (solve(sudoku)) {
                return true; 
            }
            sudoku[row][col] = 0;
        }
    }

    return false; 
}
int main() {
    cout << "========================= WELCOME TO THE SUDOKU SOLVER =========================\n\n\n";
    while (true) {
        int sudoku[N][N];

        cout << "Enter the Sudoku from left to right & top to bottom. (use 0 as blank spaces):\n";
        string input;
        getline(cin, input); 

     
        vector<string> parts;
        istringstream iss(input);
        string token;
        while (iss >> token) {
            parts.push_back(token);
        }

      
        int index = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (index < parts.size()) {
                    sudoku[i][j] = stoi(parts[index++]);
                } else {
                    sudoku[i][j] = 0; 
                }
            }
        }
        cout << "\nThe Sudoku you entered is:\n\n";
        display(sudoku);
        cout<<"\n";

        try {
            if (!checkvalid(sudoku)) {
                throw "Please Enter a valid Sudoku";
            }

            if (solve(sudoku)) {
                cout << "Solved sudoku is:\n\n";
                display(sudoku);
            } else {
                cout << "No solution exists for the given Sudoku puzzle.\n";
            }
        } catch (const char* errorMessage) {
            cout << "Error: " << errorMessage << endl;
        }

        cout << "\nDo you want to add another Sudoku puzzle? (yes/no): ";
        string choice;
        getline(cin, choice);
        if (choice != "yes") {
            break; 
        }
    }
    cout<<"THANK YOU";

    return 0;
}








