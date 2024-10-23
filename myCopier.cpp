/*
  myCopier.cpp
  created to solve HW7 problem 2 in cpe 422
  this will copy a text file and write it to another text file.
  reading the contents line by time and writing them to the other file  takes
  two cmd line args, one with file to read, the other is the file that  is being
  written.

example usage: ./myCopier ./myFavoriteText.txt ./copy.txt
  made by Shawn Farnham on 10-23-2024
*/

#include <iostream>
#include <fstream>

using namespace std;


int main (int argc, char *argv[]){
  //check to make sure there is the right amount of arguments
  if( argc != 3){
    cout << "Please enter 2 command line arguments. ";
    cout << "Each should be a filePath" << endl;
    return 0;
  }
  //make the argumanets into strings, output tje strings to show
  //user they are correct
  string readFilePath = argv[1];
  string writeFilePath = argv[2];
  cout << "the file to be read is" << readFilePath << endl;
  cout << "the file to be written is" << writeFilePath << endl;
  
  string temp;
  //making filestreams for the two files
  fstream fsr;
  fstream fsw;
  //open the two files
  fsr.open((readFilePath).c_str(), fstream::in);
  fsw.open((writeFilePath).c_str(), fstream::out);
  //get line by line from read file
  while(getline(fsr, temp, '\n')){
    //cout << "The line is: \n" << temp << endl;
    fsw << temp << endl; //save to write file the lines
  }
  //close the files
  fsr.close();
  fsw.close();
  cout << "done copying file" << endl;
  return 0;
}
