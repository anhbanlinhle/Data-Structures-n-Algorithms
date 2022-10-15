#include "Libs.h"
#include "Leaf.h"

#define TASK_1 9
#define TASK_2 3
#define TASK_3 3

using namespace std;

int main() {
    Leaf* tree = NULL;

    int task_1[TASK_1] = {2, 1, 10, 6, 3, 8, 7, 13, 20};
    int task_2[TASK_2] = {14, 0, 35};
    int task_3[TASK_3] = {6, 13, 35};

    for (int i = 0; i < TASK_1; i++)
        tree = tree->pushLeaf(tree, task_1[i]);
    
    tree->preOrder(tree);
    cout << endl;
    tree->inOrder(tree);
    cout << endl;
    tree->postOrder(tree);
    cout << endl;

    for (int i = 0; i < TASK_2; i++) 
        tree = tree->pushLeaf(tree, task_2[i]);

    tree->preOrder(tree);
    cout << endl;
    tree->inOrder(tree);
    cout << endl;
    tree->postOrder(tree);
    cout << endl;

    for (int i = 0; i < TASK_3; i++)
        tree = tree->popLeaf(tree, task_3[i]);
        
    tree->preOrder(tree);
    cout << endl;
    tree->inOrder(tree);
    cout << endl;
    tree->postOrder(tree);
    cout << endl;

}