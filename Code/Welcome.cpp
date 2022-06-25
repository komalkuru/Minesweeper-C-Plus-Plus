#include "Welcome.h"
#include "Ascii.hpp"
#include <iostream>
#include <thread>
using namespace std;

#define RED     "\033[31m"     
#define BLUE    "\033[34m"    
#define WHITE   "\033[37m"      
#define MAGENTA "\x1b[35m";

WelcomeScreen :: WelcomeScreen() {
  cout<<endl;
  cout<<MAGENTA;
  printAscii("Welcome.txt");
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  cout<<RED<<endl<<endl<<endl<<"Rules :- "<<endl<<endl;
  cout<<"1. The board is divided into cells, with mines randomly distributed."<<endl;
  cout<<"2. To win, you need to open all the cells."<<endl;
  cout<<"3. Mines variable represent the total number of mines on the board. Using this information, you can determine cells that are safe, and cells that are contain mines."<<endl;
  cout<<"4. Interact, involve and enjoy! :)"<<endl<<endl<<endl;
  
  cout<<"How to play :- "<<endl<<endl;
  cout<<"1. User will input x and y (Co-ordinates where they want to click)."<<endl;
  cout<<"2. In each step check for win or lose case."<<endl<<endl<<endl<<WHITE;
}

void WelcomeScreen :: GameStartAscii() {
  cout<<RED;
  printAscii("Start.txt");
  cout<<WHITE<<endl<<endl;
}

void WelcomeScreen :: GameEndAscii() {
  cout<<RED;
  printAscii("End.txt");
  cout<<WHITE<<endl<<endl;
}

void WelcomeScreen :: ThankYouAscii() {
  cout<<RED;
  printAscii("Thankyou.txt");
  cout<<WHITE<<endl<<endl;
}