#include<iostream>
#include<fstream>
#include<string>

using namespace std;


void printAscii(string fileName)
{
  // string line = "";
  // ifstream infile;
  // infile.open(fileName);
  // if(infile.is_open())
  // {
  //   while(getline(infile, line))
  //   {
  //     cout << line << endl;
  //   }
  // }
  // infile.close(); 

  string line = "";
  ifstream file;

  file.open(fileName);
  if(file.is_open())
  {
    while(getline(file, line))
    {
      cout << line << endl;
    }
  }

  file.close();
}