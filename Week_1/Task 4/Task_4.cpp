#include <iostream>
using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

int main(){
    int n;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (a[j] < a[i])
                swap(a[i], a[j]);
        }
    }
    
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

}