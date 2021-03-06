#include <iostream>
#include <fstream>
#include <array>
#include <algorithm>

using namespace std;

void task1(const string &, int);

int main() {
    string path;
    fstream fileStream;
    char confirmChar('m');

    cout << "AoC, day 6.\n";
    do {
        cout << "Type path to input file with puzzles:\n";
        cin >> path;

        fileStream.open(path);
        if(fileStream.is_open())
        {
            fileStream.close();
            cout << "File successfully opened!\n";
            cout << "First task data:\n";
            task1(path, 80);

            cout << "Second task data:\n";
            task1(path, 256);

            break;
        }
        else
        {
            fileStream.close();
            cout << "Wrong path to file. Not opened. Try again? y/n - ";
            cin >> confirmChar;
            if(confirmChar == 'y' || confirmChar == 'Y') confirmChar = 'm';
        }
    }while(confirmChar == 'm');
}

void task1(const string &path, const int days)
{
    fstream stream;
    stream.open(path);

    string line;
    array<unsigned long long, 9> numOfFishPerState = {};
    while (getline(stream, line, ','))
    {
        int fishState = stoi(line);
        ++numOfFishPerState[fishState];
    }

    for (unsigned i = 0; i < days; ++i)
    {
        auto numGivingBirth = numOfFishPerState[0];
        rotate(numOfFishPerState.begin(), numOfFishPerState.begin() + 1, numOfFishPerState.end());
        numOfFishPerState[6] += numGivingBirth;
    }

    unsigned long long sum = 0;
    for(auto m : numOfFishPerState)
        sum += m;

    cout << sum << '\n';
}