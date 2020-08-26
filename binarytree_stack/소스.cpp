#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <stdio.h>
#include <stack>
#pragma warning(disable:4996)

using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

//LVR
void inOrder(struct Node* root)
{
    stack<Node*> s;
    Node* curr = root;

    while (curr != NULL || s.empty() == false)
    {
        while (curr != NULL)
        {
            s.push(curr);
            curr = curr->left;
        }

        curr = s.top();
        s.pop();
        cout << curr->data << " ";

        curr = curr->right;
    }
}

//VLR
void preorder(struct Node* root)
{
    stack<Node*> s;
    Node* curr = root;

    while (curr != NULL || s.empty() == false)
    {
        while (curr != NULL)
        {
            cout << curr->data << " ";

            if (curr->right) s.push(curr->right);
            curr = curr->left;
        }

        if (s.empty() == false)
        {
            curr = s.top();
            s.pop();
        }
    }
}

//LRV
void postorder(struct Node* root)
{
    stack<Node*> s1, s2;
    s1.push(root);
    Node* curr;
    
    while (!s1.empty())
    {
        curr = s1.top();
        s1.pop();
        s2.push(curr);

        if (curr->left) s1.push(curr->left);
        if (curr->right) s1.push(curr->right);
    }

    while (!s2.empty())
    {
        curr = s2.top();
        s2.pop();
        cout << curr->data << " ";
    }
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
    inOrder(root);

    cout << "\nPostorder traversal of binary tree is \n";
    postorder(root);

    return 0;
}

