#include "Libs.h"
#include "Stack.h"

using namespace std;
int main() {
    Stack list;
    int query, data;
    string scan;

    cin >> query;

    for (int i = 0; i < query; i++) {
        cin >> scan;

        if (scan == "push") {
            cin >> data;
            list.push(data);
        }

        else if (scan == "pop") {
            list.pop();
        }
    }
    list.print();
}

