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
Logic
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
