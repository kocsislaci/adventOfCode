#include <string>
#include <iostream>
#include <fstream>
#include <regex>

using namespace std;

const regex pattern("\\d+");

int main()
{
    ifstream inputFile;
    inputFile.open("../input6.txt");

    smatch match;
    string line;

    int result = 1;
    vector<unsigned long long> times = vector<unsigned long long>();
    vector<unsigned long long> records = vector<unsigned long long>();

    if (getline(inputFile, line)) {
        while (regex_search(line, match, pattern)) {
            times.push_back(stoll(match.str()));
            line = match.suffix().str();
        }
    }
    if (getline(inputFile, line)) {
        while (regex_search(line, match, pattern))
        {
            records.push_back(stoll(match.str()));
            line = match.suffix().str();
        }
    }

    // input
    // const T (times[i]) [s], const s (records[i]) [m], const a (1) [m/s^2]
    // unknown
    // v [m/s], t [s]

    // equation
    // s = v * (T - t)
    // v = t * a
    // ->
    // s = (t * a)(T - t)
    // 0 = - (a * t^2) + (a * T * t^1) - (s * t^0)

    // solver formula
    // A = -a = -1
    // B = (a * T) = T depends on input
    // C = -s
    // t1,t2 = (-B +- sqrt(B^2 - 4AC)) / 2A
    // ->
    // discriminant = T^2 - 4s
    // t1 = (-T + sqrt(T^2 + 4s)) / -2
    // t2 = (-T - sqrt(T^2 + 4s)) / -2

    for (int i = 0; i < times.size(); i++) {
        unsigned long long discriminant = times[i] * times[i] - 4 * records[i];
        if (discriminant <= 0) {
            continue;
        }
        long double discriminantSquared = sqrt((long double)discriminant);
        long double t1 = ((long double)times[i] - discriminantSquared) / (long double)2;
        long double t2 = ((long double)times[i] + discriminantSquared) / (long double)2;
        long double higher = max(t1, t2);
        long double lower = min(t1, t2);
        if (higher == floor(higher)) {
            higher--;
            lower++;
        }
        result *= (unsigned long long)floor(higher) - (unsigned long long)ceil(lower) + 1;
    }
    
    inputFile.close();
    cout << "The result is: " << result << endl;
    return 0;
}
