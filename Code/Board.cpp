#include "Board.h"
#include<iostream>
#include<random>
#include<cstring>

#define MAXSIDE 25

using namespace std;

Board :: Board() {
  gameOver = false;
  isFirstMove = true;
  Mine = '*';
}

bool Board :: isValid(int row, int col) {
  return (row >= 0) && (row < size) &&
		(col >= 0) && (col < size);
}

void Board :: createBoard(char realboard[][MAXSIDE], char myboard[][MAXSIDE], int size) {
  srand(time(0));

  for(int i = 0; i < size; ++i) {
    for( int j = 0; j < size; ++j) {
      myboard[i][j] = realboard[i][j] = ' ';
    }
  } 
  
  return;
}

void Board :: dotedDesign(int col) {
  cout<<" ";
  for(int i = 0; i < col; ++i) {
    cout << "--";
  }
  cout << endl;
}

void Board :: printColumnNumbers(int col) {
  for(int i = 0; i < col; ++i) {
    cout << "|" << i+1;
  }
  cout << "|" << endl;
  cout << endl;
  dotedDesign(col);
}

void Board :: printBoard(char myboard[][MAXSIDE], int size ) {
  printColumnNumbers(size);
  for(int i = 0; i < size; ++i) {
    for( int j = 0; j < size; ++j) {
      cout << "|" << myboard[i][j]; 
    }
    cout << "|" << endl;
    dotedDesign(size);
  }
  cout << endl;
  return;
}

void Board :: assignMoves(int Moves[][2], int movesLeft, int size) {
  bool mark[MAXSIDE * MAXSIDE];

  memset(mark, false, sizeof(mark));

    for(int i=0; i < movesLeft; ){
    int random = rand() % (size * size);
    int x = random / size;
    int y = random % size;

    if(mark[random] == false) {
      Moves[i][0] = x;
      Moves[i][1] = y;

      mark[random] = true;
      i++;
    }
  }
  return;
}

int Board :: findMinimumMines(int size) {
  int totalMines;

  totalMines = size + 1;
  
  if(size > 15 && size <= 25) {
    totalMines = (size + 5);
    return totalMines;
  }

  if( size >= 9 && size < 15) {
    totalMines = size + 1;
    return totalMines;
  }
  return totalMines;
}

void Board :: replaceMine(char board[][MAXSIDE], int row, int col, int size) {
  for(int i = 0; i < size-1; ++i) {
    for( int j = 0; j < size-1; ++j) {
      if(board[i][j] != Mine) {
        board[i][j] = Mine;
        board[row][col] = ' ';
        return;
      }
    }
  }
  return;
}

void Board :: placeMines(int Mines[][2], char realboard[][MAXSIDE], int size) {
  int mineCount = findMinimumMines(size);
  bool mark[MAXSIDE * MAXSIDE];

  memset(mark, false, sizeof(mark));

  int i=0;
  if(isFirstMove) {
    while(i < mineCount) {
      int random = rand() % (size * size);
      int randomRow = random / size;
      int randomColumn = random % size;
  
      if(mark[random] == false) {
        Mines[i][0] = randomRow;
        Mines[i][1] = randomColumn;

        realboard[Mines[i][0]][Mines[i][1]] = Mine;
        mark[random] = true;
        ++i;
      }
    }
    isFirstMove = false;
  }
  return;
}

void Board:: cheatMinesweeper (char realboard[][MAXSIDE], int size, int Mines[][2]) {
  printf ("The mines locations are-\n");
  placeMines(Mines, realboard, size);
  printBoard(realboard,size);
	return;
}

bool Board:: isMine(int row, int col, char board[][MAXSIDE]) {
  if(board[row][col] == Mine)
    return true;
  else
    return false;
}

int Board :: countAdjacentMines(int row, int col, int size, int Mines[][2], char realboard[][MAXSIDE]) {
  int count = 0;
  
  if (isValid (row-1, col) == true){
		if (isMine (row-1, col, realboard) == true)
		  count++;
	}
  
	if (isValid (row+1, col) == true) {
		if (isMine (row+1, col, realboard) == true)
      count++;
	}
  
	if (isValid (row, col+1) == true) {
    if (isMine (row, col+1, realboard) == true)
	    count++;
	}
  
	if (isValid (row, col-1) == true)	{
		if (isMine (row, col-1, realboard) == true)
			count++;
	}
  
	if (isValid (row-1, col+1) == true)	{
		if (isMine (row-1, col+1, realboard) == true)
			count++;
  }
  
	if (isValid (row-1, col-1) == true)	{ 
		if (isMine (row-1, col-1, realboard) == true)
			count++;
	}
  
	if (isValid (row+1, col+1) == true)	{
		if (isMine (row+1, col+1, realboard) == true)
			count++;
	}
  
	if (isValid (row+1, col-1) == true)	{
		if (isMine (row+1, col-1, realboard) == true)
			count++;
	}

	return (count);
}

bool Board:: playMinesweeperUntil(char myboard[][MAXSIDE], char realboard[][MAXSIDE],int Mines[][2], int row, int col, int *movesLeft) {
  
  if(myboard[row][col] != ' ') {
    return false;
  }

  if(realboard[row][col] == Mine){
    myboard[row][col] = Mine;

    int mineCount = findMinimumMines(size);
    
    for(int i = 0; i < mineCount; i++){
      myboard[Mines[i][0]][Mines[i][1]] = Mine;
    }

    cout<<"Mines : "<<mineCount<<endl;
    printBoard(myboard, size);
    cout<<endl<<"Oops you stepped on the mine"<<endl<<"You lose"<<endl;
    return true;
    
  } else {
    int count = countAdjacentMines(row, col, size, Mines, realboard);
    (*movesLeft)--;
  
    myboard[row][col] = '0' + count;
  
    if(!count) {
			if (isValid (row-1, col) == true) {
				if (isMine (row-1, col, realboard) == false)
				playMinesweeperUntil( myboard, realboard, Mines, row-1, col, movesLeft);
			}
      
			if (isValid (row+1, col) == true) {
				if (isMine (row+1, col, realboard) == false)
					playMinesweeperUntil( myboard, realboard, Mines, row+1, col, movesLeft);
			}
      
			if (isValid (row, col+1) == true)	{
				if (isMine (row, col+1, realboard) == false)
					playMinesweeperUntil( myboard, realboard, Mines, row, col+1, movesLeft);
			}
      
			if (isValid (row, col-1) == true)	{
				if (isMine (row, col-1, realboard) == false)
					playMinesweeperUntil( myboard, realboard, Mines, row, col-1, movesLeft);
			}
      
			if (isValid (row-1, col+1) == true)	{
				if (isMine (row-1, col+1, realboard) == false)
					playMinesweeperUntil( myboard, realboard, Mines, row-1, col+1, movesLeft);
			}
      
			if (isValid (row-1, col-1) == true)	{
				if (isMine (row-1, col-1, realboard) == false)
					playMinesweeperUntil( myboard, realboard, Mines, row-1, col-1, movesLeft);
			}
      
			if (isValid (row+1, col+1) == true)	{
				if (isMine (row+1, col+1, realboard) == false)
					playMinesweeperUntil( myboard, realboard, Mines, row+1, col+1, movesLeft);
			}
      
			if (isValid (row+1, col-1) == true)	{
				if (isMine (row+1, col-1, realboard) == false)
					playMinesweeperUntil( myboard, realboard, Mines, row+1, col-1, movesLeft);
			}
    }
  return false;
  }
}

void Board:: execute() {
  Board();
  cout<<"Enter the size of board between 9 to 25 : ";
  cin>>size;
  int maxMines = findMinimumMines(size);
  int movesLeft = size * size - maxMines;

  int Mines[maxMines][2];
  int Moves[movesLeft][2];
  
  createBoard(realboard, myboard, size);
  placeMines(Mines, realboard, size);
  assignMoves(Moves, movesLeft, size);

  int currentMoveIndex = 0;

  while(gameOver == false) {
    cout << endl <<"Mines : "<< maxMines << endl;

    cout << endl <<"current status of board : "<< endl;
    // if you want to see where mines are present then comment out belows line
    // cheatMinesweeper(realboard, size, Mines);
    printBoard(myboard, size); 

    coordinates = true;
    while(coordinates == true) {
      cout << "Enter the x and y co-ordinates : ";
      cin >> x >> y;
      if((x == 0 || x > size) || (y == 0 || y > size)) {
        cout << endl <<"Please enter the coordinates between 1 to " << size<<"."<<endl<<endl;
      } else {
        coordinates = false;
      }
    }
    
    int x1 = x-1;
    int y1 = y-1;

    if(currentMoveIndex == 0) {
      if(isMine( x1, y1, realboard) == true) {
        replaceMine(realboard, x1, y1, size);
      }
    }
    
    currentMoveIndex++;
    gameOver = playMinesweeperUntil(myboard, realboard, Mines, x1, y1, &movesLeft);

    if ((gameOver == false) && (movesLeft == 0))
		{
      for(int i = 0; i < maxMines; i++){
      myboard[Mines[i][0]][Mines[i][1]] = Mine;
    }

    printBoard(myboard, size);
			cout << endl << "You won !" << endl;
			gameOver = true;
		}
  }
  return;
}