#include <iostream>

#define ENTRY 11
#define TASK 11

int h4sh(int k) {
    return (2*k + 5)%ENTRY;
}

using namespace std;
int main() {
    // Output array.
    int array[ENTRY];
    for (int i = 0; i < ENTRY; i++)
        array[i] = -1;

    // Input array
    int task[TASK] = {12, 44, 13, 88, 23, 94, 11, 39, 20, 16, 5};
    
    // Check collision array
    bool blank[ENTRY];
    for (int i = 0; i < ENTRY; i++)
        blank[i] = 0;

    int tempHash;
    for (int i = 0; i < TASK; i++) {
        tempHash = h4sh(task[i]);

        // Check collison
        while(blank[tempHash] == 1) { 
            tempHash+=1;
            if (tempHash > 10)
                tempHash-=ENTRY;
        }

        // Put data into hash array
        array[tempHash] = task[i];
        blank[tempHash] = 1;
    }

    for (int i = 0; i < ENTRY; i++) {
        if (array[i] == -1)
            cout << " _ ";
        else
            cout << " " << array[i] << " ";
    }
}