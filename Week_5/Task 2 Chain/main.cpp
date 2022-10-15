#include "Libs.h"
#include "DLL.h"

#define ENTRY 11
#define TASK 11

int h4sh(int k) {
    return (2*k + 5)%ENTRY;
}

using namespace std;
int main() {
    // Initiate output array
    DLL* h4shTable[ENTRY];
    for (int i = 0; i < ENTRY; i++)
        h4shTable[i] = new DLL();

    // Input array
    int task[TASK] = {12, 44, 13, 88, 23, 94, 11, 39, 20, 16, 5};

    // Start hashing
    int tempHash;
    for(int i = 0; i < TASK; i++) {
        tempHash = h4sh(task[i]);
        h4shTable[tempHash]->pushTail(task[i]);
    }

    for (int k = 0; k < ENTRY; k++) {
        cout << k << ":"; 
        if (!h4shTable[k]->isEmpty()) {
            h4shTable[k]->fowardPrint();
            cout << endl;
        }
        else
            cout << " blank\n";   
    }
}