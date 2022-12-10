#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
  //cout << "Hello World!";
  //

  fstream newfile;

  newfile.open("C:/Users/Joels/OneDrive/Desktop/inputday3.txt",ios::in); //open a file to perform read operation using file object
    cout << "Hello World!";
    if (newfile.is_open()){ //checking whether the file is open
      string tp;
      string firstHalf;
      string secondHalf;
      int length = 0;
      int total = 0;
      while(getline(newfile, tp)){ //read data from file object and put it into string.
        cout << tp << " ";
        length = tp.length();
        firstHalf = tp.substr(0,length/2);
        secondHalf = tp.substr(length/2, length);
        cout << " length: " << length << " First Half: " << firstHalf << " Second Half: " << secondHalf << "\n";
        for (int i = 0; i < (length/2); i++)
        {
          if (firstHalf.find(secondHalf[i])!=std::string::npos) // Find the similar character in both parts of the array
          {
            cout << " Similar Character: " << secondHalf[i] << " Ascii number: " << int(secondHalf[i]) - 96 <<"\n";
            if (isupper(secondHalf[i])) // checks if uppercase
            {
              total = total + (secondHalf[i] - 38); // brings values down to the range for uppercase
            }
            else
            {
              total = total + (secondHalf[i] - 96); // brings values down to the range for lowercase
            }
            break;
          }
        }
      }
      cout << "Total: " << total;
      newfile.close(); //close the file objec
  }
  return 0;
}