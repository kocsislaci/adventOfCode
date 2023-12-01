#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#include <ctype.h>

using namespace std;

int main() {
    // load input
    string filePath = "./input.txt";
    string input;
    ifstream inputFile;
    inputFile.open(filePath);
    stringstream stringStream;
    stringStream << inputFile.rdbuf();
    inputFile.close();
    input = stringStream.str();

    // split to lines
    vector<string> lines = vector<string>();
    string::size_type pos = 0;
    string::size_type prev = 0;
    while ((pos = input.find('\n', prev)) != std::string::npos)
    {
        lines.push_back(input.substr(prev, pos - prev));
        prev = pos + 1;
    }

    // find 
    int result = 0;
    for (int i = 0; i < lines.size(); i++)
    {
        int linePos = 0;
        vector<int> foundNumbers = vector<int>();
        while (linePos != lines[i].size())
        {
            if (isdigit(lines[i].at(linePos)))
                foundNumbers.push_back(lines[i].at(linePos) - 48); // offset to 0-9
            else {

                if (lines[i].at(linePos) == 'o' && linePos + 2 <= lines[i].size()) {
                    if (lines[i].at(linePos + 1) == 'n')
                        if (lines[i].at(linePos + 2) == 'e') 
                            foundNumbers.push_back(1);
                }
                else if (lines[i].at(linePos) == 't' && linePos + 2 <= lines[i].size()) {
                    if (lines[i].at(linePos + 1) == 'w' )
                    {
                        if (lines[i].at(linePos + 2) == 'o') {
                            foundNumbers.push_back(2); 
                        }
                    }
                    else if (lines[i].at(linePos + 1) == 'h' && linePos + 4 <= lines[i].size())
                    {
                        if (lines[i].at(linePos + 2) == 'r') {
                            if (lines[i].at(linePos + 3) == 'e') {
                                if (lines[i].at(linePos + 4) == 'e') {
                                    foundNumbers.push_back(3);
                                }
                            }
                        }
                    }
                }
                if (lines[i].at(linePos) == 'f' && linePos + 3 <= lines[i].size())
                {
                    if (lines[i].at(linePos + 1) == 'o') {
                        if (lines[i].at(linePos + 2) == 'u') {
                            if (lines[i].at(linePos + 3) == 'r') {
                                foundNumbers.push_back(4);
                            }
                        }
                    }
                    else if (lines[i].at(linePos + 1) == 'i') {
                        if (lines[i].at(linePos + 2) == 'v') {
                            if (lines[i].at(linePos + 3) == 'e') {
                                foundNumbers.push_back(5);
                            }
                        }
                    }
                }
                else if (lines[i].at(linePos) == 's' && linePos + 2 <= lines[i].size())
                {
                    if (lines[i].at(linePos + 1) == 'i') {
                        if (lines[i].at(linePos + 2) == 'x') {
                            foundNumbers.push_back(6);
                        }
                    }
                    else if (lines[i].at(linePos + 1) == 'e' && linePos + 4 <= lines[i].size())
                    {
                        if (lines[i].at(linePos + 2) == 'v') {
                            if (lines[i].at(linePos + 3) == 'e') {
                                if (lines[i].at(linePos + 4) == 'n') {
                                    foundNumbers.push_back(7);
                                }
                            }
                        }
                    }
                }
                else if (lines[i].at(linePos) == 'e' && linePos + 4 <= lines[i].size())
                {
                    if (lines[i].at(linePos + 1) == 'i') {
                        if (lines[i].at(linePos + 2) == 'g') {
                            if (lines[i].at(linePos + 3) == 'h') {
                                if (lines[i].at(linePos + 4) == 't') {
                                    foundNumbers.push_back(8);
                                }
                            }
                        }
                    }
                }
                else if (lines[i].at(linePos) == 'n' && linePos + 3 <= lines[i].size())
                {
                    if (lines[i].at(linePos + 1) == 'i') {
                        if (lines[i].at(linePos + 2) == 'n') {
                            if (lines[i].at(linePos + 3) == 'e') {
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
        result += (foundNumbers.at(0)) * 10 + (foundNumbers.at(foundNumbers.size() - 1));
    }
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