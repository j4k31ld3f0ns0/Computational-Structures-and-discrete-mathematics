/*
Generate a binary tree using a numerical sort order (smaller is left,
greater is right). Hard code the input in this exact order:
50, 75, 25, 15, 60, 35, 90, 42, 20, 27, 5, 55, 95, 80, 70
Using that input, I know what the tree looks like and the correct output.

Print out Preorder, Inorder, and Postorder outputs.
*/

//utilize pointers and recursion to navigate linked list.
//VLR, LVR, LRV

#include <iostream>
#include <list>
using namespace std;

class binaryNode {
    
public:
    int value;
    binaryNode* left = nullptr;
    binaryNode* right = nullptr;
    binaryNode(int x) {
        this->value = x;
    }
    /*
    void insert(int x) {
        //need to check if there are nodes below this one. Left is less than, right is greater than.
        if (this->right == nullptr && this->left == nullptr) { //both are empty, this is a leaf node.
            binaryNode* newNode = new binaryNode(x);
            if (this->value > x) {
                
                this->right = newNode;
            }
            else if (this->value <= x) {
                this->left = newNode;
            }
        }
    }
    */
};

class binaryTree {
    binaryNode* root = nullptr;
public:
    binaryTree(list<int> unsortedInts) {
        for (int x : unsortedInts) {
            insert(x);
        }
    }
    void insert(int x) {
        if (root == nullptr) {
            //this is the first value of the tree
            root = new binaryNode(x);
        }
        else { //traverse da tree and put in a node.
            insert(root, x);
        }
    }
    void insert(binaryNode* currentNode, int x) {
        if (x > currentNode->value) { //inserted value is bigger
            if (currentNode->right != nullptr) {//something is in the right node
                insert(currentNode->right, x);
            }
            else {
                binaryNode* newNode = new binaryNode(x);
                currentNode->right = newNode;
            }
        }
        else if (x <= currentNode->value) { //inserted value is equal or less
            if (currentNode->left != nullptr) { //something in left node
                insert(currentNode->left, x);
            }
            else {
                binaryNode* newNode = new binaryNode(x);
                currentNode->left = newNode;
            }
        }
    }
    void preorder() {
        cout << "Preorder traversal:";
        preorder(root);
        cout << endl;
    }
    void preorder(binaryNode* currentNode) { //VLR
        cout << " " << currentNode->value;
        if (currentNode->left == nullptr && currentNode->right == nullptr) { //this is a leaf node
            return;
        }
        else {
            if (currentNode->left != nullptr) {
                preorder(currentNode->left);
            }
            if (currentNode->right != nullptr) {
                preorder(currentNode->right);
            }
            return;
        }
    }
    void inorder() { //LVR
        cout << "Inorder traversal:";
        inorder(root);
        cout << endl;
    }
    void inorder(binaryNode* currentNode) {
        if (currentNode->left == nullptr && currentNode->right == nullptr) { //this is a leaf node
            cout << " " << currentNode->value;
            return;
        }
        else {
            if (currentNode->left != nullptr) {
                inorder(currentNode->left);
            }
            cout << " " << currentNode->value;
            if (currentNode->right != nullptr) {
                inorder(currentNode->right);
            }
        }
    }
    void postorder() { //LRV
        cout << "Postorder traversal:";
        postorder(root);
        cout << endl;
    }
    void postorder(binaryNode* currentNode) {
        if (currentNode->left == nullptr && currentNode->right == nullptr) { //this is a leaf node
            //return;
            //do nuffin.
        }
        else {
            if (currentNode->left != nullptr) {
                postorder(currentNode->left);
            }
            if (currentNode->right != nullptr) {
                postorder(currentNode->right);
            }
        }
        cout << " " << currentNode->value;
        return;
    }
};

int main()
{
    list<int> unsortedhardcodedIntegers = {
        50, 75, 25, 15, 60, 35, 90, 42, 20, 27, 5, 55, 95, 80, 70
    };
    binaryTree* tree = new binaryTree(unsortedhardcodedIntegers);
    tree->preorder();
    tree->inorder();
    tree->postorder();
}
