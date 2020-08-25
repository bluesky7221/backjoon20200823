#include <iostream>
#include <vector>
#include <string>
#include <deque>
#pragma warning(disable:4996)
using namespace std;

struct Node
{
    int data;
    struct Node* left, * right;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

//LRV
void printPostorder(struct Node* node)
{
    if (node == NULL)
        return;

    printPostorder(node->left);
    printPostorder(node->right);
    cout << node->data << " ";
}

//LVR
void printInorder(struct Node* node)
{
    if (node == NULL)
        return;

    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}

//VLR
void printPreorder(struct Node* node)
{
    if (node == NULL)
        return;

    cout << node->data << " ";
    printPreorder(node->left);
    printPreorder(node->right);
}

int main()
{
    /* Constructed binary tree is
              1
            /   \
          2      3
        /  \
      4     5
    */
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "\nPreorder traversal of binary tree is \n";
    printPreorder(root);

    cout << "\nInorder traversal of binary tree is \n";
    printInorder(root);

    cout << "\nPostorder traversal of binary tree is \n";
    printPostorder(root);

    return 0;
}