// FileMerge.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    string inputFile1 = "file1.txt";
    string inputFile2 = "file2.txt";
    string outputFile = "merged_output.txt";

    ifstream file1(inputFile1);
    ifstream file2(inputFile2);
    ofstream outFile(outputFile);

    string line1, line2;

    // Read the first line from each file
    if (getline(file1, line1) && getline(file2, line2)) {
        while (true) {
            string key1 = line1.substr(0, line1.find(','));
            string key2 = line2.substr(0, line2.find(','));

            if (key1 < key2) {
                outFile << line1 << endl;
                if (!getline(file1, line1)) {
                    // Write the remaining lines from file2
                    outFile << line2 << endl;
                    while (getline(file2, line2)) {
                        outFile << line2 << endl;
                    }
                    break;
                }
            }
            else {
                outFile << line2 << endl;
                if (!getline(file2, line2)) {
                    // Write the remaining lines from file1
                    outFile << line1 << endl;
                    while (getline(file1, line1)) {
                        outFile << line1 << endl;
                    }
                    break;
                }
            }
        }
    }

    file1.close();
    file2.close();
    outFile.close();

    cout << "Files merged successfully!" << endl;

    return 0;
}