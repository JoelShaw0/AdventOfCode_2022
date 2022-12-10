#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
  //cout << "Hello World!";
  //

  fstream newfile;

  newfile.open("C:/Users/Joels/OneDrive/Desktop/input.txt",ios::in); //open a file to perform read operation using file object
    //cout << "Hello World!";
    if (newfile.is_open()){ //checking whether the file is open
      string tp;
      int total = 0;
      int max = 0;
      int secondmax = 0;
      int thirdmax = 0;
      while(getline(newfile, tp)){ //read data from file object and put it into string.
        if (tp != "")
        {
          total = total + stoi(tp);
        }
        else
        {
          if (max >= total)
          {
            if (secondmax < total && total < max)
            {
              secondmax = total;
              cout << "\nSecond most Calories: " << secondmax;
            } 
            if (thirdmax < total && total < secondmax)
            {
              thirdmax = total;
              cout << "\nThird most Calories: " << thirdmax;
            }
            total = 0;
          }
          else
          {
            if (thirdmax < secondmax)
            {
              thirdmax = secondmax;
            }
            if (secondmax < max)
            {
              secondmax = max;
            }
            max = total;
            cout << "\nMost Calories: " << max;
      //cout << "\nTotal of all three:" << max + secondmax + thirdmax;
            total = 0;
          }
        }
      }
      newfile.close(); //close the file objec
      cout << "\n\nMost Calories: " << max;
      // Most == 69289
      cout << "\nSecond most Calories: " << secondmax;
      // Second == 68321
      cout << "\nThird most Calories: " << thirdmax;
      // Third == 68005
      cout << "\nTotal of all three:" << max + secondmax + thirdmax;
  }
  return 0;
}