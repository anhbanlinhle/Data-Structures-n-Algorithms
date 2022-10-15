#include "Libs.h"
using namespace std;

// get rect area by given top left and bottom right cordinates.
int area(int** arr, int x1, int y1, int x2, int y2) {
    int area = 0;
    // scan from left side to right side.
    for (int i = x1; i <= x2; i++)
        // scan from top side to bottom side.
        for (int j = y1; j <= y2; j++)
            // add value
            area += arr[i][j];
    return area;
}

int main() {
    // open input file.
    fstream testFile;
    testFile.open("test/Matrix.txt",ios::in);

    // get rect size.
    int m, n;
    testFile >> m >> n;
    
    // implement rect.
    int** arr = new int*[m];
    for (int i = 0; i < m; i++) {
        *(arr + i) = new int[n];
    }

    // get data for rect.
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            testFile >> arr[i][j];
    testFile.close();

    // set max as the first rect.
    int x1 = 0, x2 = 0, y1 = 0, y2 = 0;
    int max = area(arr, 0, 0, 0, 0);

    // scan and calculate all possible rect.
    // scan for top left cordinate.
    for (int i = 0; i < m; i++) { for (int j = 0; j < n; j++) {
        // scan for bottom right cordinate.
        for (int o = i; o < m; o++) { for (int p = j; p < n; p++) {
            // check if area larger than max.
            if (area(arr, i, j, o, p) > max)
                // record max area and its cordinates.
                { max = area(arr, i, j, o, p); x1 = i; y1 = j; x2 = o; y2 = p; }             
        }}
    }}

    // save max area found and its cordinates to output file.
    testFile.open("Matrix.out",ios::out);
    testFile << x1+1 << " " << y1+1 << " " << x2+1 << " " << y2+1 << " " << max;
}