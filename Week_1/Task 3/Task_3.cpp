#include <iostream>
using namespace std;

unsigned long long gcd(unsigned long long m, unsigned long long n) {
    unsigned long long temp;
    while(n != 0) {
        temp = m % n;
        m = n;
        n = temp;
    }
    return m;
}

int main(){
	long m,n;
	cin >> m >> n;
	cout << gcd(m,n);
}