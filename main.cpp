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
  inputFile.open("../input3.txt");

  smatch match;
  string line;
  vector<string> lines = vector<string>(3); // keep size 3

  int result = 0;
  bool justOneMoreTime = true;

  vector<array<int, 4> > gearAcc = vector<array<int, 4> >();

  // if we find a new one then check if we have and if they the same then * and
  // delete from list
  int Y = 0;
  while (getline(inputFile, line) || justOneMoreTime) {
    lines[2] = lines[1]; // new line then drop the last one
    lines[1] = lines[0];
    lines[0] = line;

    if (lines[0].empty()) { // we arrived to the last line
      justOneMoreTime = false;
    }

    int X = 0;
    string acc = "";
    bool canCalc = false, isLast = false;

    while (X < lines[1].size()) { // check line along X

      if (isdigit(lines[1][X])) {

        std::array<int, 4> gear;

        acc += lines[1][X];

        if ((X + 1) == lines[1].size()) { // last in the row
          isLast = true;
        }

        if (!isdigit(lines[1][X + 1]) &&
            (X + 1) < lines[1].size()) { // right neighbour is not number
          isLast = true;
        }

        if (isLast) {
          for (int dy = -1; dy < 2; dy++) {
            for (int dx = -acc.size(); dx < 2; dx++) {

              if (lines[dy + 1].empty()) { // empty line
                continue;
              }

              if ((dy == 0 && dx != -acc.size() && dx != 1) || (-1 == X + dx) ||
                  (lines[1].size() == X + dx)) { // middle and out of bounds
                continue;
              }

              if (lines[dy + 1][X + dx] == '*') { // found one gear!
                cout << X + dx << " " << Y - dy << " " << acc << endl;
                gear[0] = X + dx;
                gear[1] = Y - dy;
                gear[2] = stoi(acc);
                gear[3] = 1;
                bool exists = false;
                for (int i = 0; i < gearAcc.size(); i++) {
                  if (gear[0] == gearAcc[i][0] && gear[1] == gearAcc[i][1]) {
                    if (gearAcc[i][3] == 2) {
                      gearAcc[i][2] = 0; // mutable lists can kill our for
                    } else {
                      gearAcc[i][2] =
                          gear[2] * gearAcc[i][2]; // accumulate the value
                      gearAcc[i][3] += 1;
                    }
                    exists = true;
                  }
                }
                if (!exists) {
                  gearAcc.push_back(gear);
                }
                dx = 2; // can finish search
                dy = 2;
              }
            }
          }
          isLast = false;
          acc = "";
        }
      }
      X++;
    }
    Y++;
  }

  for (int i = 0; i < gearAcc.size(); i++) {
    if (gearAcc[i][3] == 2) {
      result += gearAcc[i][2];
    }
  }

  inputFile.close();
  cout << "The result is: " << result << endl;
  return 0;
}

// test data:
// 467 * 35 + 755 * 598
// result shoudl be: 467835
