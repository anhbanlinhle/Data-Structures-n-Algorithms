#include "Libs.h"
using namespace std;

void genStr(string base, int len, string result, vector<bool> check) {
    if(result.length() == len)
        cout << result << " ";
    else {
        for (int i = 0; i < len; i++) {
            if (check[i] == 0) {
                check[i] = 1;
                genStr(base, len, result + base[i], check);
                check[i] = 0;
            }
        }
    }
}

int main() {
    string base;
    cin >> base;
    
    // base = "";
    // int n; cin >> n;
    // for (int i = 1; i <= n; i++) base+=to_string(i);

    int len = base.length();

    vector<bool> check;
    for (int i = 0; i < len; i++)
        check.push_back(0);
    
    genStr(base, len, "", check);
}