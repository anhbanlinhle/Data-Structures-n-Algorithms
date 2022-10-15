#include "Libs.h"

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> tree[N+1];
    int u, v;

    for (int i = 0; i < M; i++) {
        cin >> u >> v;
        tree[u].push_back(v);
    }

    for (int i = 0; i < N; i++) {
        if (tree[i].size() > 2) {
            cout << "\nNOT BINARY TREE\n";
            return 0;
        }
    }
    cout << "\nWOW BINARY TREE xD\n" << endl;

    vector<int>::iterator pos;
    
    // preorder
    vector<int> preOrder;
    
    for (int i = 1; i <= N; i++) {
        if (tree[i].size() != 0) {
            for (int j = tree[i].size() - 1; j >= 0; j--) {
                pos = find(preOrder.begin(), preOrder.end(), i);
                preOrder.insert(pos, tree[i][j]);
            }
        }
    }

    cout << "Pre Order : 1";
    for (int i = preOrder.size() - 1; i >= 0; i--)
        cout << " " << preOrder[i];
    cout << endl;

    // post order
    vector<int> postOrder;

    for (int i = 1; i <= N; i++) {
        if (tree[i].size() != 0) {
            for (int j = 0; j < tree[i].size() ; j++) {
                pos = find(postOrder.begin(), postOrder.end(), i);
                postOrder.insert(pos, tree[i][j]);
            }
        }
    }

    cout << "Post Order :";
    for (int i = 0; i < postOrder.size(); i++)
        cout << " " << postOrder[i];
    cout << " 1" << endl;

    // in order
    vector<int> inOrder;
    inOrder.push_back(1);
    for (int i = 1; i <= N; i++) {
        if (tree[i].size() != 0) {
            pos = find(inOrder.begin(), inOrder.end(), i);
            inOrder.erase(pos);
            inOrder.insert(pos, tree[i][0]);
            inOrder.insert(pos, i);
            pos = find(inOrder.begin(), inOrder.end(), i);
            inOrder.insert(pos, tree[i][1]);
        }
    }

    cout << "In Order :";
    for (int i = inOrder.size() - 1; i >= 0; i--) {
        if (inOrder[i] != 0)
            cout << " " << inOrder[i];

    }
    cout << endl;

}
