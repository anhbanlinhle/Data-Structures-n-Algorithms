#include "Libs.h"
#include "DLL.h"

using namespace std;
int main() {
    DLL list;
    int num, data;
    
    cin >> num;

    for (int i = 0; i < num; i++) {
        cin >> data;
        list.pushHead(data);
    }
    cout << list.countTriplet();
}

