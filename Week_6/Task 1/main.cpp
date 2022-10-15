#include "Libs.h"

using namespace std;
int main() {
    vector<double> output;
    double temp;

    // read input file.
    fstream testFile;
    testFile.open("test/numbers.txt",ios::in);
    if (testFile.is_open())
        while (!testFile.eof()) {
            testFile >> temp;
            output.push_back(temp);
        }
    testFile.close();

    // sort from input file.
    for (int i = 0; i < output.size(); i++) {
        for (int j = i + 1; j < output.size(); j++) {
            if (output[i] > output[j])
                swap(output[i], output[j]);
        }
    }

    // write output file.
    testFile.open("numbers.sorted",ios::out);
    if (testFile.is_open())
        for (int i = 0; i < output.size(); i++)
            testFile << setprecision(15) << output[i] << " ";
}