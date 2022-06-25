#include "Board.h"
#include "Welcome.h"
#include <bits/stdc++.h>
using namespace std;

int main() {
  Board board;
  WelcomeScreen message;
  char startGame;
  cout<<"Press 'Y' to start the game or 'N' to end the game : ";
  cin>>startGame;
  if(startGame == 'Y' || startGame == 'y') {
    message.GameStartAscii();
    board.execute();
    startGame = 'X';
  } else if(startGame == 'N' || startGame == 'n' ) {
    startGame = 'X';
  }

  if(startGame == 'X') {
    message.GameEndAscii();
    message.ThankYouAscii();
  }
}