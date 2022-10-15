#include "Libs.h"
#include "Queue.h"

using namespace std;
int main() {
    Queue list;
    int query, data;
    string scan;

    cin >> query;

    for (int i = 0; i < query; i++) {
        cin >> scan;

        if (scan == "enqueue") {
            cin >> data;
            list.enqueue(data);
        }

        else if (scan == "dequeue") {
            list.dequeue();
        }
    }
    list.print();
}

