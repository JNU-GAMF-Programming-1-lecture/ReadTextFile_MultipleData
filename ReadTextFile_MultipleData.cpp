/*ReadTextFile_MultipleData.cpp*/

#include <iostream>
#include <fstream>
#include <string>
#include <format>
#include <sstream>
#include <iomanip>

using namespace std;

int main() 
{
  // Open the input file
  ifstream in("multipledata.txt");

  if (!in.is_open()) 
  {
    cerr << "Error opening file." << endl;
    return 1;
  }

  string line;

  // Print the table header.
  cout << format("{:<20} {:>10} {:>10}\n", "Name", "Weight", "Height");
  cout << string(42, '-') << "\n"; // Horizontal line.

  string surname, firstname;
  double weight;
  int height;
  while (getline(in, surname, ','))
  {
    in >> firstname;
    in >> weight >> height;
    in.ignore();
    // Display the data in tabular format
    cout << format("{:<20} {:>10.2f} {:>10}\n", surname + ", " + firstname, weight, height);
  }

  //// Read each line from the file.
  //while (getline(in, line)) 
  //{
  //  istringstream ss(line);
  //  string surname, firstname;
  //  double weight;
  //  int height;

  //  // Parse the surname and firstname (e.g., "Smith, John")
  //  getline(ss, surname, ',');
  //  ss >> firstname;
  //  ss >> weight >> height;

  //  // Display the data in tabular format
  //  cout << format("{:<20} {:>10.2f} {:>10}\n", surname + ", " + firstname, weight, height);
  //}

  in.close();
  return 0;
}
