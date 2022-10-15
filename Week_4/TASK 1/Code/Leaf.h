
#ifndef LEAF_H
#define LEAF_H

class Leaf {
    public:
        Leaf();
        ~Leaf();

        Leaf(int data);
        int key;
        int height;
        Leaf* parent;
        Leaf* left;
        Leaf* right;

        Leaf* pushLeaf(Leaf* root, int data);
        Leaf* popLeaf(Leaf* root, int data);
        int leftMost(Leaf* root);
        int rightMost(Leaf* root);
        void preOrder(Leaf* root);
        void inOrder(Leaf* root);
        void postOrder(Leaf* root);
        int countHeight(Leaf* root);
};

#endif