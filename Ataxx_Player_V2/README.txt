Name: Talha Ibn Aziz
ID: 1669108
Course: CMPUT 657
Assignment 4

The Makefile compiles the program and creates a file called ataxx.
The command "./ataxx" runs the created program.

Initially Naive MCTS with custom semi-random moves were used.
After suggestions from Professor Buro, UCB1 variation of MCTS is used.
The latter runs slower compared to the former (less iterations), but still
performs much better compared to the former. However, it is still dominated
by Minimax with Alpha-Beta pruning.
