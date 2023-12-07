#include <fstream>
#include <iostream>
#include <regex>
#include <string>

using namespace std;

const regex numberPattern("\\d+");
const regex wordPattern("\\b\\w+\\b");

enum Color {
  RED,
  GREEN,
  BLUE,
};

int main() {
  ifstream inputFile;
  inputFile.open("./input2.txt");

  smatch match;
  string line;

  int result = 0;
  vector<int> colorMax = vector<int>(); // r g b
  colorMax.push_back(0);
  colorMax.push_back(0);
  colorMax.push_back(0);

  while (getline(inputFile, line)) {
    colorMax[0] = 0;
    colorMax[1] = 0;
    colorMax[2] = 0;
    if (regex_search(line, match, numberPattern)) {
      // we get the first number to get the needed numbers later
    }
    while (regex_search(line, match, numberPattern)) {
      int number = stoi(match.str());
      line = match.suffix().str();
      if (regex_search(line, match, wordPattern)) {
        switch (match.str()[0]) {
        case 'r':
          if (number > colorMax[0]) {
            colorMax[0] = number;
          }
          break;
        case 'g':
          if (number > colorMax[1]) {
            colorMax[1] = number;
          }
          break;
        case 'b':
          if (number > colorMax[2]) {
            colorMax[2] = number;
          }
          break;
        default:
          break;
        }
      }
    }
    result += colorMax[0] * colorMax[1] * colorMax[2];
  }

  inputFile.close();
  cout << "The result is: " << result << endl;
  return 0;
}
