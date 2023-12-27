# Sudoku_Solver
This project uses a C++ program to solve Sudoku puzzles provided by the user.
Sudoku is a popular logic-based number placement puzzle, and this project utilises
backtracking to efficiently find the solutions. The program interacts with the user
to input Sudoku puzzles in a concise format, where each row of the puzzle is
provided as a single line with spaces separating the numbers. It then checks the
validity of the input using various algorithms to ensure the rules of Sudoku are
followed.
The project employs dynamic arrays known as vectors and leverages string
manipulation to parse the user input. The C++ Standard Library's functions such as
`std::stoi` and `std::istringstream` facilitate the conversion of string elements to
integers. The program implements a backtracking algorithm to efficiently solve the
Sudoku puzzle by trying different possible values for empty cells until a valid
solution is found.
A user-friendly interface allows users to input multiple Sudoku puzzles
consecutively. After solving each puzzle, the program prompts the user to add
another puzzle or terminate the process. Error handling is incorporated to
gracefully handle invalid inputs and prevent abrupt termination.
Error handling is an essential aspect of the program. It ensures that the user's
input adheres to the Sudoku puzzle's rules before attempting to solve it. If an
invalid puzzle is provided, the program promptly notifies the user of the error
without terminating abruptly.
To find the solution to a Sudoku puzzle, the program uses a backtracking
algorithm. Backtracking is an efficient technique that tries different possible
values for each empty cell, exploring all possible paths until a valid solution is
found. If a conflict arises, the algorithm backtracks and explores other
possibilities.

Logic:

In order to solve the Sudoku, the basic algorithm utilised is the backtracking
algorithm. The backtracking algorithm is a recursive algorithm used to solve
problems that involve finding a solution among a large number of possibilities. It is
based on the idea of trying out all possible choices and "backtracking" or undoing
choices that lead to dead-ends or incorrect solutions.
In this case the algorithm starts by searching for an empty cell in the Sudoku grid
(i.e., a cell with the value 0). The algorithm then tries filling the empty cell with a
number from 1 to 9, one by one. After placing a number in the cell, the algorithm
checks if the current configuration is valid according to Sudoku rules viz:
The number must not appear in the same row.
The number must not appear in the same column.
The number must not appear in the same 3x3 subgrid.
If the current configuration is valid, the algorithm recursively proceeds to the next
empty cell and tries filling it with a number. This process continues until all cells
are filled, and a complete solution is found. If the current configuration is not valid
or no valid number can be placed in the cell, the algorithm backtracks. It undoes
the last placement of the number and goes back to the previous cell to try a
different number.The algorithm repeats steps 3 to 5 until it finds a valid solution or
exhausts all possibilities. If all possibilities are exhausted, it backtracks further to
the previous cell, exploring alternative choices.
When all cells are filled with valid numbers according to the Sudoku rules, the
algorithm has found a complete and valid solution for the Sudoku puzzle.

Code Explanation: 

The line #include <bits/stdc++.h> is a shortcut used to include a large set of
standard C++ header files in one line. This is done so as to minimise the number of
header includes and quickly access various standard library functionalities without
specifying each individual header file.
First a function to check if the Sudoku input is valid or not is written, called
checkvalid(). The checkvalid function checks the validity of the user's input for the
Sudoku puzzle. It takes a 2D integer array (sudoku) as input and returns a boolean
indicating whether the puzzle is valid or not. The function checks each row, each
column, and each 3x3 subgrid for duplicates, ensuring that the Sudoku rules are
followed. It uses additional boolean arrays to keep track of the numbers that have
been used in each row, column, and subgrid to efficiently detect duplicates.
Next a function to print the sudoku grid display() is created. This function uses a
2D integer array as input and outputs the Sudoku grid on the console. In order to
make the grid easier to read, it is formatted with horizontal lines between 3x3
subgrids.
The fillit() function checks if a given number (num) can be placed in a specific cell
in the Sudoku grid. It takes the grid, row, column, and the number as input and
returns a boolean indicating whether the placement is valid. The function checks
the row, column, and 3x3 subgrid to ensure that the number is not repeated in
any of these regions, based on the Sudoku rules.
The backtracking algorithm is implemented by the solve() function to solve the
Sudoku puzzle. It accepts a 2D integer array (sudoku) as input and outputs a
boolean indicating the existence or absence of a viable solution. The fillit function,
which is described above, is used by the function to check each step for validity
before trying a different number (1 to 9) in each empty cell. If a valid number is
entered, the function moves on to the following empty cell; otherwise, it goes
back to the previous cell.
The main data structure used in the program is a 2D integer array named sudoku.
It represents the Sudoku puzzle as a 9x9 grid. Each cell of the grid stores an
integer, which corresponds to a number from 1 to 9 or 0 for an empty cell. The
array is used to store the initial puzzle input provided by the user and to store the
solution found by the backtracking algorithm.
Vectors are dynamic arrays provided by the C++ Standard Template Library (STL).
In the program, vectors are used to split the user's input string into individual cell
values and store them temporarily in the parts vector. The use of vectors simplifies
string splitting and dynamically manages the list of tokens (cell values) without
needing to handle memory allocation manually.
The program uses boolean arrays to keep track of the numbers that have been
used in each row, column, and 3x3 subgrid of the Sudoku puzzle. These boolean
arrays help to efficiently check the validity of the Sudoku puzzle using the
checkvalid function. When filling numbers in the grid, the corresponding boolean
values are updated to detect any duplicates and ensure that the Sudoku rules are
followed.
'try' and 'catch' are used in the program to handle exceptions. The 'checkvalid'
function throws an exception with the message 'Please enter a valid Sudoku' when
it finds an invalid Sudoku problem. The 'checkvalid' function call is contained
within a 'try' block in the'main' function. When the 'checkvalid' function returns
an exception, the 'catch' block catches it and prints the message "Error: Please
enter a valid Sudoku." This makes the application more user-friendly and robust by
enabling it to gracefully handle failures, notify the user about erroneous input,
and continue running without abrupt termination.
In the main function of the Sudoku Solver program, the input is being taken in a
user-friendly manner using the `getline` function. The program prompts the user
to enter the Sudoku puzzle as a single line, with spaces between each cell. The
`getline` function reads the entire line of input and stores it as a string called
`input`. The program then calls the `split` function to split the input string into
individual cell values. The `split` function utilises the `std::istringstream` to
efficiently extract tokens (cell values) from the input string, and it returns a vector
called `parts`, containing the individual cell values. The program then converts
these string cell values to integers and fills the Sudoku grid accordingly. This input
approach allows the user to input the entire Sudoku puzzle in a single line, making
the process more convenient and efficient.

Pseudocode for the project is given below:
1. Define constants:
N = 9 (size of the Sudoku grid)
2. Define function checkvalid(sudoku):
- For each row and each column, create arrays rowUsed[N] and colUsed[N] to
keep track of the numbers used.
- Check each row and column for duplicates and return false if found.
- Check each 3x3 subgrid for duplicates and return false if found.
- If no duplicates are found, return true.
3. Define function display(sudoku):
- Print the Sudoku grid in a formatted way.
4. Define function fillit(sudoku, row, col, num):
- Check if the given number 'num' can be placed at cell (row, col) in the Sudoku
grid.
- Return false if 'num' is already present in the row, column, or 3x3 subgrid;
otherwise, return true.
5. Define function empty(sudoku, row, col):
- Find the first empty cell in the Sudoku grid (cell with value 0).
- Update the 'row' and 'col' parameters with the coordinates of the empty cell.
- Return true if an empty cell is found, otherwise return false.
6. Define function solve(sudoku):
- If there is no empty cell in the Sudoku grid, return true (Sudoku is solved).
- Find an empty cell using the empty() function.
- Try filling each number from 1 to 9 in the empty cell using the fillit() function.
- If a number can be placed at the cell without violating the Sudoku rules, set the
cell with that number and recursively call solve() to continue solving the remaining
grid.
- If the Sudoku is solved successfully (solve() returns true), return true.
- If no number can be placed at the cell, reset the cell to 0 and return false
(backtrack).
7. Define function main():
- Display a welcome message.
- Enter a loop to keep solving Sudoku puzzles until the user wants to stop.
- Read the Sudoku input from the user and store it in the 2D array 'sudoku'.
- Display the entered Sudoku using the display() function.
- Check if the entered Sudoku is valid using the checkvalid() function. If not
valid, display an error message.
- If valid, try to solve the Sudoku using the solve() function.
- If the Sudoku is solvable, display the solved Sudoku using the display()
function; otherwise, display a message indicating that no solution exists.
- Ask the user if they want to add another Sudoku puzzle. If the answer is 'no,'
exit the loop.
- Display a thank you message.
8. Call the main() function to start the Sudoku solver.
