#include <iostream>
using namespace std;

int main(){
    
    string test;
    getline(cin,test);


    for (int i = test.size() - 1; i >= 0; i--)
        cout << test[i];

}