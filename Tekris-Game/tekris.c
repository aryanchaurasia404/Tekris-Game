#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Define the game board dimensions
#define BOARD_WIDTH 10
#define BOARD_HEIGHT 20

// Define the tetromino shapes
#define NUM_TETROMINOS 7
int tetrominos[NUM_TETROMINOS][4][2] = {
    {{0, 0}, {1, 0}, {2, 0}, {3, 0}}, // I-Shape
    {{0, 0}, {1, 0}, {2, 0}, {2, 1}}, // J-Shape
    {{0, 1}, {1, 1}, {2, 1}, {2, 0}}, // L-Shape
    {{0, 0}, {1, 0}, {1, 1}, {2, 1}}, // O-Shape
    {{0, 0}, {1, 0}, {2, 0}, {1, 1}}, // S-Shape
    {{0, 1}, {1, 1}, {2, 1}, {1, 0}}, // T-Shape
    {{0, 0}, {1, 0}, {1, 1}, {2, 0}}  // Z-Shape
};

// Define the game state
int board[BOARD_HEIGHT][BOARD_WIDTH];
int currentTetromino;
int currentX, currentY;
int score;
int level;
int linesCleared;

// Function to initialize the game board
void initBoard() {
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {
            board[i][j] = 0;
        }
    }
}

// Function to draw the game board
void drawBoard() {
    clear();
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {
            if (board[i][j] == 1) {
                mvprintw(i, j, "#");
            } else {
                mvprintw(i, j, " ");
            }
        }
    }
    mvprintw(BOARD_HEIGHT + 1, 0, "Score: %d", score);
    mvprintw(BOARD_HEIGHT + 2, 0, "Level: %d", level);
    mvprintw(BOARD_HEIGHT + 3, 0, "Lines Cleared: %d", linesCleared);
    refresh();
}

// Function to handle user input
void handleInput(int c) {
    switch (c) {
        case 'j': // Move left
            if (currentX > 0) {
                currentX--;
            }
            break;
        case 'l': // Move right
            if (currentX < BOARD_WIDTH - 1) {
                currentX++;
            }
            break;
        case 'k': // Move down
            if (currentY < BOARD_HEIGHT - 1) {
                currentY++;
            }
            break;
        case ': // Rotate
            rotateTetromino();
            break;
    }
}

// Function to rotate the tetromino
void rotateTetromino() {
    int newTetromino[NUM_TETROMINOS][4][2];
    for (int i = 0; i < 4; i++) {
        newTetromino[currentTetromino][i][0] = tetrom