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
  inputFile.open("../input2.txt");

  smatch match;
  string line;

  int result = 0;
  bool possible = true;
  vector<int> containing = vector<int>(); // r g b
  containing.push_back(12);
  containing.push_back(13);
  containing.push_back(14);
  vector<int> numbers = vector<int>();
  vector<Color> words = vector<Color>();

  while (getline(inputFile, line)) {

    int gameNumber;
    if (regex_search(line, match, numberPattern)) {
      gameNumber = stoi(match.str());
    }
    while (regex_search(line, match, numberPattern) && possible) {
      int number = stoi(match.str());
      line = match.suffix().str();
      if (regex_search(line, match, wordPattern)) {
        switch (match.str()[0]) {
        case 'r':
          if (number > containing[0]) {
            possible = false;
          }
          break;
        case 'g':
          if (number > containing[1]) {
            possible = false;
          }
          break;
        case 'b':
          if (number > containing[2]) {
            possible = false;
          }
          break;
        default:
          break;
        }
      }
    }
    if (possible) {
      result += gameNumber;
    } else {
      possible = true;
    }
  }

  inputFile.close();
  cout << "The result is: " << result << endl;
  return 0;
}
