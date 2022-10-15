#include <iostream>
using namespace std;

long gcd(long m, long n) {
    // make sure gcd is a positive number.
    if (m < 0) m *= -1;
    if (n < 0) n *= -1;
    
    // special case.
    if (m == 0 || n == 0) return m + n;
    
    // base case.
    if (m == n) return m;

    // use recursion to decrease input until meet base case.
    if (m > n) return gcd(m - n, n);
    return gcd(m, n - m);
}

int main() {
    int m, n;
    cin >> m >> n;
    cout << gcd(m, n);
}