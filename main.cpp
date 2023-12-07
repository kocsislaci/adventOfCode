#include <fstream>
#include <iostream>
#include <regex>
#include <string>

using namespace std;

const regex numberPattern("\\d+");
const regex wordPattern("\\b\\w+\\b");

// we need 3 lines at once

int main() {
  ifstream inputFile;
  inputFile.open("./input3.txt");

  smatch match;
  string line;
  vector<string> lines = vector<string>(3); // keep size 3

  int result = 0;
  bool forTheLastLine = true;

  while (getline(inputFile, line) || forTheLastLine) {
    lines[2] = lines[1]; // new line then drop the last one
    lines[1] = lines[0];
    lines[0] = line;

    if (lines[0].empty()) {
      forTheLastLine = false;
    }

    int X = 0;
    string acc = "";
    bool canCalc = false, isLast = false;

    while (X < lines[1].size()) { // check line along X

      if (isdigit(lines[1][X])) {

        acc += lines[1][X];

        if ((X + 1) == lines[1].size()) { // last in the row
          isLast = true;
        }
        if (!isdigit(lines[1][X + 1]) &&
            (X + 1) < lines[1].size()) { // right neighbour
          isLast = true;
        }

        for (int dx = -1; dx < 2; dx++) {
          for (int dy = -1; dy < 2; dy++) {

            if (canCalc) { // already found special char for this accumulated
                           // integer
              continue;
            }

            if (lines[dy + 1].empty()) { // empty line
              continue;
            }

            if (dy == 0 && dx == 0 || (-1 == X + dx) ||
                (lines[1].size() == X + dx)) { // middle and out of bounds
              continue;
            }

            if (!isdigit(lines[dy + 1][X + dx]) &&
                lines[dy + 1][X + dx] != '.') { // finish
              canCalc = true;
              dx = 2;
              dy = 2;
            }
          }
        }
        if (isLast) {
          if (acc.size() > 0 && canCalc) {
            result += stoi(acc);
          }
          canCalc = false;
          isLast = false;
          acc = "";
        }
      }
      X++;
    }
  }

  inputFile.close();
  cout << "The result is: " << result << endl;
  return 0;
}

// test data:
// 467+35+633+617+592+755+664+598
// result shoudl be: 4361
