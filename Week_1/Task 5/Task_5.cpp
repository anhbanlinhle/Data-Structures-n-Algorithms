#include <iostream>
using namespace std;

int main(){
    int a[5];
    int min, max;
    
    for (int i = 0; i < 5; i++)
        cin >> a[i];
    
    min = a[0];
    max = a[0];
    
    for (int i = 0; i < 5; i++) {
        if (a[i] > max)
            max = a[i];
        if (a[i] < min)
            min = a[i];
    }
    
    cout << min + max;
}