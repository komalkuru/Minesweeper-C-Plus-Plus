#pragma once
#define MAXSIDE 25

class Board {

int size;
char realboard[MAXSIDE][MAXSIDE];
char myboard[MAXSIDE][MAXSIDE];
bool gameOver;
int mineCount;
char Mine;
int mines;
bool isFirstMove;
bool coordinates;
int x,y;

public:
Board();
void execute();
bool isValid(int, int);

void createBoard(char[][MAXSIDE], char[][MAXSIDE], int);

void dotedDesign(int);
void printColumnNumbers(int);
void printBoard(char[][MAXSIDE], int);
bool isMine(int, int, char[][MAXSIDE] );
void replaceMine(char[][MAXSIDE], int, int, int);
bool playMinesweeperUntil(char[][MAXSIDE], char[][MAXSIDE],int[][2], int, int, int*);
int countAdjacentMines(int, int, int, int[][2], char[][MAXSIDE]);
void adjacentCellRecursion(int, int, int, int*, int[][2]);
void placeMines(int[][2], char[][MAXSIDE],int);
void assignMoves(int[][2], int, int);

void cheatMinesweeper (char[][MAXSIDE], int, int[][2]);
int findMinimumMines(int);
bool containCoordinates(int*, int*);

int totalMoveSize(int);


};