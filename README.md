# Tekris Game
Tetris Game in C

Description:

This is a classic implementation of the Tetris game using C language. The game features a 10x20 grid, 7 different tetromino shapes, scoring, level progression, and line clearing. The game uses the ncurses library for rendering the game board and handling user input.

Features:

10x20 game board
7 different tetromino shapes (I, J, L, O, S, T, Z)
Scoring system
Level progression
Line clearing
Rotation of tetrominos
User input handling (left, right, down, rotate)
How to Play:

Compile the game using gcc tetris.c -o tetris -lncurses
Run the game using ./tetris
Use the following keys to control the game:
j: Move left
l: Move right
k: Move down
Space: Rotate tetromino
The game will automatically clear lines and update the score and level as you play.
Code:
 
