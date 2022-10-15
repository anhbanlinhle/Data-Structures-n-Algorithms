#include <iostream>
using namespace std;

int main(){

// Input

	long n;
    cin >> n;

    long a[n];
    for (long i = 0; i < n; i++)
        cin >> a[i];

    long count = 0;

// Output

	for (long i = 0; i < n - 1; i++) 
        for(long j = i+1; j < n; j++) 
            if (a[i] == a[j])
                count++;

    cout << count;
}