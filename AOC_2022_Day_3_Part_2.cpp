#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
  //cout << "Hello World!";
  //

  fstream newfile;

// Absolute madness
  newfile.open("C:/Users/Joels/OneDrive/Desktop/inputday3.txt",ios::in); //open a file to perform read operation using file object
    if (newfile.is_open()){ //checking whether the file is open
      string tp;
      string first;
      string second;
      string third;
      int firstlength;
      int secondlength;
      int thirdlength;
      string hotseat;
      string secondseat;
      string thirdseat;
      int track = 0;
      int length = 0;
      int total = 0;
      while(getline(newfile, first)){ //read data from file object and put it into string.
        getline(newfile, second);
        getline(newfile, third);

        firstlength = first.length();
        secondlength = second.length();
        thirdlength = third.length();

        length = std::min(firstlength, secondlength);
        length = std::min(length, thirdlength);
        
        if (length == firstlength)
        {
          hotseat = first;
          secondseat = second;
          thirdseat = third;
        }
        else if (length == secondlength)
        {
          hotseat = second;
          secondseat = first;
          thirdseat = third;
        }
        else
        {
          hotseat = third;
          secondseat = first;
          thirdseat = second;
        }

        for (int i = 0; i < length; i++)
        {
          if (secondseat.find(hotseat[i])!=std::string::npos) // Find the similar character in both parts of the array
          {
              if (thirdseat.find(hotseat[i])!=std::string::npos)
              {
                cout << " " << first << " " << second << " " << third <<  " Similar Character: " << hotseat[i] << "\n";
                if (isupper(hotseat[i])) // checks if uppercase
                {
                  cout << " Ascii number: " << int(hotseat[i]) - 38 <<"\n";
                  total = total + (hotseat[i] - 38); // brings values down to the range for uppercase
                  cout << "Total: " << total;
                }
                else
                {
                  cout << " Ascii number: " << int(hotseat[i]) - 96 <<"\n";
                  total = total + (hotseat[i] - 96); // brings values down to the range for lowercase
                  cout << "Total: " << total;
                }
                track++;
                break;
              }
          }
        }
        
      }
      cout << "Total: " << total << "Track: " << track;
      newfile.close(); //close the file objec
  }
  return 0;
}