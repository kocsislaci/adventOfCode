#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#include <ctype.h>

using namespace std;

int main() {
    cout << "Hello Advent of Code\n";

    // load input
    string filePath = "../input.txt";
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
                foundNumbers.push_back(lines[i].at(linePos));
            linePos++;
        }
        if (foundNumbers.size() == 0) {
            cout << "Line number " << i << " result: No number here" << endl;
            continue;
        }
        int localResult = (foundNumbers.at(0) - 48) * 10 + (foundNumbers.at(foundNumbers.size() - 1) - 48);
        cout << "Line number " << i << " result: " << localResult << endl;
        result += localResult;
    }
    cout << "The result is: " << result << endl;
    return 0;
}
