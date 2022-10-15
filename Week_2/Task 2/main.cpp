#include "Libs.h"
#include "DLL.h"

using namespace std;
int main() {
    DLL list;
    int query, position, data;
    string scan;

    cin >> query;

    for (int i = 0; i < query; i++) {
        cin >> scan;

        if (scan == "insert") {
            cin >> position >> data;
            list.push(position, data);
        }

        else if (scan == "delete") {
            cin >> position;
            list.pop(position);
        }

        cout << endl;
        list.print();
        cout << endl;
    }
    list.print();
}

