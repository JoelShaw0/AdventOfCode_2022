#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
  //cout << "Hello World!";
  //

  fstream newfile;

  newfile.open("C:/Users/Joels/OneDrive/Desktop/input2.txt",ios::in); //open a file to perform read operation using file object
    cout << "Hello World!";
    if (newfile.is_open()){ //checking whether the file is open
      string tp;
      int total = 0;
      int max = 0;
      cout << "Hello World!";
      while(getline(newfile, tp)){ //read data from file object and put it into string.
        //cout << tp << ""; //print the data of the string
        if (tp != "")
        {
          total = total + stoi(tp);
        }
        else
        {
          if (max >= total)
          {
            total = 0;
          }
          else
          {
            max = total;
            total = 0;
          }
        }
      }
      newfile.close(); //close the file objec
      cout << max;
  }
  return 0;
}