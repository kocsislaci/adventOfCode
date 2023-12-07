#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int day1() {
  ifstream inputFile;
  inputFile.open("./input.txt");

  int result = 0;
  string line;
  while (getline(inputFile, line)) {
    int linePos = 0;
    vector<int> foundNumbers = vector<int>();
    while (linePos != line.size()) {
      if (isdigit(line.at(linePos)))
        foundNumbers.push_back(line.at(linePos) - 48); // offset to 0-9
      else {

        if (line.at(linePos) == 'o' && linePos + 2 <= line.size()) {
          if (line.at(linePos + 1) == 'n')
            if (line.at(linePos + 2) == 'e')
              foundNumbers.push_back(1);
        } else if (line.at(linePos) == 't' && linePos + 2 <= line.size()) {
          if (line.at(linePos + 1) == 'w') {
            if (line.at(linePos + 2) == 'o') {
              foundNumbers.push_back(2);
            }
          } else if (line.at(linePos + 1) == 'h' &&
                     linePos + 4 <= line.size()) {
            if (line.at(linePos + 2) == 'r') {
              if (line.at(linePos + 3) == 'e') {
                if (line.at(linePos + 4) == 'e') {
                  foundNumbers.push_back(3);
                }
              }
            }
          }
        }
        if (line.at(linePos) == 'f' && linePos + 3 <= line.size()) {
          if (line.at(linePos + 1) == 'o') {
            if (line.at(linePos + 2) == 'u') {
              if (line.at(linePos + 3) == 'r') {
                foundNumbers.push_back(4);
              }
            }
          } else if (line.at(linePos + 1) == 'i') {
            if (line.at(linePos + 2) == 'v') {
              if (line.at(linePos + 3) == 'e') {
                foundNumbers.push_back(5);
              }
            }
          }
        } else if (line.at(linePos) == 's' && linePos + 2 <= line.size()) {
          if (line.at(linePos + 1) == 'i') {
            if (line.at(linePos + 2) == 'x') {
              foundNumbers.push_back(6);
            }
          } else if (line.at(linePos + 1) == 'e' &&
                     linePos + 4 <= line.size()) {
            if (line.at(linePos + 2) == 'v') {
              if (line.at(linePos + 3) == 'e') {
                if (line.at(linePos + 4) == 'n') {
                  foundNumbers.push_back(7);
                }
              }
            }
          }
        } else if (line.at(linePos) == 'e' && linePos + 4 <= line.size()) {
          if (line.at(linePos + 1) == 'i') {
            if (line.at(linePos + 2) == 'g') {
              if (line.at(linePos + 3) == 'h') {
                if (line.at(linePos + 4) == 't') {
                  foundNumbers.push_back(8);
                }
              }
            }
          }
        } else if (line.at(linePos) == 'n' && linePos + 3 <= line.size()) {
          if (line.at(linePos + 1) == 'i') {
            if (line.at(linePos + 2) == 'n') {
              if (line.at(linePos + 3) == 'e') {
                foundNumbers.push_back(9);
              }
            }
          }
        }
      }
      linePos++;
    }
    if (foundNumbers.size() == 0) {
      continue;
    }
    result +=
        (foundNumbers.at(0)) * 10 + (foundNumbers.at(foundNumbers.size() - 1));
  }
  inputFile.close();
  cout << "The result is: " << result << endl;
  return 0;
}

// task one
// result: 55108

// one      3

// two      3
// three    5    X

// four     4    XX
// five     4    XX

// six      3
// seven    5    X

// eight    5    X
// nine     4    XX

// 1. o, t, f, s, e, n

// task two
// result: 56324
