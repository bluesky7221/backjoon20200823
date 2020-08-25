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
void postorder(struct Node* node)
{
    if (node == NULL)
        return;

    postorder(node->left);
    postorder(node->right);
    cout << node->data << " ";
}

//LVR
void inorder(struct Node* node)
{
    if (node == NULL)
        return;

    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}

//VLR
void preorder(struct Node* node)
{
    if (node == NULL)
        return;

    cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
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
    preorder(root);

    cout << "\nInorder traversal of binary tree is \n";
    inorder(root);

    cout << "\nPostorder traversal of binary tree is \n";
    postorder(root);

    return 0;
}