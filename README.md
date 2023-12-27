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
