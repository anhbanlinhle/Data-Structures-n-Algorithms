#include "Libs.h"

using namespace std;
int main() {
    int n;
    cin >> n;
    int len = pow(2,n);
    string arr[len];
    n--;
    int count = 0;
    while (n>=0) {
        int temp = 0;
        while(temp < len) {
            for(int i = 1; i<=pow(2,n); i++) {
                arr[temp] += "0";
                temp++;
                count++;
            }
            for(int i = 1; i<=pow(2,n); i++) {
                arr[temp] += "1";
                temp++;
                count++;
            }
        }
        n--;
    }
    for (int i = 0; i< len;i++)
        cout << arr[i] << endl;
    cout << count;
}