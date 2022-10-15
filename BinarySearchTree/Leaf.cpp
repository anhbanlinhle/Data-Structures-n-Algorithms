#include "Leaf.h"
#include "Libs.h"

Leaf::Leaf() {
    key = 0;
    height = 0;
    parent = NULL;
    left = NULL;
    right = NULL;
}

Leaf::~Leaf() {

}

Leaf::Leaf(int data) {
    key = data;
    height = 0;
    parent = NULL;
    left = NULL;
    right = NULL;
}

Leaf* Leaf::pushLeaf(Leaf* root, int data) {
    if (root == NULL) {
        root = new Leaf(data);
    }
    else if (root->key < data){
        root->right = pushLeaf(root->right, data);
        root->right->parent = root;
    }
    else {
        root->left = pushLeaf(root->left, data);
        root->left->parent = root;
    }
    return root;
}

Leaf* Leaf::findKey(Leaf* root, int data) {
    if (root == NULL)
        return NULL;
    if (root->key == data)
        return root;
    else if (root->key < data)
        return findKey(root->right, data);
    else
        return findKey(root->left, data);
}

Leaf* Leaf::popLeaf(Leaf* root, int data) {
    if (root == NULL)
        return root;
    if (root->key < data)
        root->right = popLeaf(root->right, data);
    else if (root->key > data)
        root->left = popLeaf(root->left, data);
    else {
        if (root->left == NULL) {
            Leaf* temp = root->right;
            free(root);
            return temp;
        }
        if (root->right == NULL) {
            Leaf* temp = root->left;
            free(root);
            return temp;
        }
        root->key = leftMost(root->right);
        root->right = popLeaf(root->right, root->key);
    }
    return root;
}

Leaf* Leaf::returnRoot(Leaf* root) {
    if (root->parent != NULL)
        root = returnRoot(root->parent);
    return root;
}

int Leaf::leftMost(Leaf* root) {
    while (root->left != NULL)
        root = root->left;
    return root->key;
}

int Leaf::rightMost(Leaf* root) {
    while (root->right != NULL)
        root = root->right;
    return root->key;
}

void Leaf::preOrder(Leaf* root) {
    if (root == NULL)
        return;
    else {
        std::cout << " " << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void Leaf::inOrder(Leaf* root) {
    if (root == NULL)
        return;
    else {
        inOrder(root->left);
        std::cout << " " << root->key << " ";
        inOrder(root->right);
    }
}

void Leaf::postOrder(Leaf* root) {
    if (root == NULL)
        return;
    else {
        postOrder(root->left);
        postOrder(root->right);
        std::cout << " " << root->key << " ";
    }
}

int Leaf::countHeight(Leaf* root) {
    if(root == NULL)
        return 0;
    else
        height = ( countHeight(root->left) > countHeight(root->right)
                 ? countHeight(root->left) : countHeight(root->right) );
    return height;
}





