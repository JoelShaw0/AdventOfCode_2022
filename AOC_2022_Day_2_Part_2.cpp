#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
  fstream newfile;

  newfile.open("C:/Users/Joels/OneDrive/Desktop/inputday2.txt",ios::in); //open a file to perform read operation using file object
    //cout << "Hello World!";
    int total = 0;
    if (newfile.is_open()){ //checking whether the file is open
      string tp;
      string opponent;
      string yourMove;
      //cout << "Hello World!";
      while(getline(newfile, tp)){ //read data from file object and put it into string.  
        yourMove = tp[2];
        opponent = tp[0];
        //cout << opponent;
        //cout << yourMove << "\n";
        //if ()
        if (yourMove == "X") // Lose
        {
          if (opponent == "A") // Rock
          {
            total = total + 3; 
          }
          else if (opponent == "B") // Paper -
          {
            total = total + 1;
          }
          else if (opponent == "C") // Scissors
          {
            total = total + 2;
          }
          yourMove = "";
          opponent = "";
        }
        else if(yourMove == "Y") // Draw
        {
          if (opponent == "A") // Rock Win
          {
            total = total + 4;
          }
          else if (opponent == "B") // Paper Tie
          {
            total = total + 5;
          }
          else if (opponent == "C") // Scissors Loss
          {
            total = total + 6;
          }
          yourMove = "";
          opponent = "";
        }else if(yourMove == "Z") // Win
        {
          if (opponent == "A") // Rock Loss
          {
            total = total + 8;
          }
          else if (opponent == "B") // Paper Win
          {
            total = total + 9;
          }
          else if (opponent == "C") // Scissors Tie
          {
            total = total + 7;
          }
          yourMove = "";
          opponent = "";
        }
        //cout << tp << " "; //print the data of the string
      }
      cout << total;
      newfile.close(); //close the file objec
  }
  return 0;
}