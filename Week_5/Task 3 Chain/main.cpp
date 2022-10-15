#include "Libs.h"
#include "DLL.h"

#define ENTRY 17
#define TASK 10

int h4sh(int k) {
    return (k + 3)%ENTRY;
}

using namespace std;
int main() {
    // Initiate output array
    DLL* h4shTable[ENTRY];
    for (int i = 0; i < ENTRY; i++)
        h4shTable[i] = new DLL();

    // Input array
    int task[TASK] = {1, 3, 18, 8, 23, 35, 11, 36, 20, 16};

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