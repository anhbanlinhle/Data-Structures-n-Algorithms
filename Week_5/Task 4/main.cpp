#include "Libs.h"
#include "DLL.h"

#define INSERT "Insert"
#define DELETE "Delete"
#define INFOR "Infor"


using namespace std;
int main() {
    // Initiate university list.
    DLL* uni = new DLL();

    // Number of queries.
    int query;
    cin >> query;

    string operation, id, name, cLass;
    
    // Start scanning
    for (int i = 0; i < query; i++) {
        // Ignore enter.
        cin.ignore();
        // Scan operation.
        getline(cin,operation,'(');   
        // Check operation.

        // Insert.
        if (operation == INSERT) {
            getline(cin,id,',');
            getline(cin,name,',');
            getline(cin,cLass,')');
            Student temp = Student(id,name,cLass);
            uni->pushHead(temp);
        }

        // Delete.
        else if (operation == DELETE) {
            getline(cin,id,')');
            uni->pop(id);
        }

        // Infor.
        else if(operation == INFOR) {
            getline(cin,id,')');
            uni->print(id);
        }
    }
}

/* Testcase
Insert(1,Tuan,K61CS)
Insert(2,Vinh,K43C)
Infor(3)
Infor(2)
Delete(2)
Infor(2)
*/