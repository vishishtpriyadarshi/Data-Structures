//
// Created by Vishisht Priyadarshi on 11-09-2019.
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Node
{
    Node* left;
    Node* right;

    int data;
};

Node* newNode(int data)                                     // Creates a new Node
{
    Node* node = new Node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}



Node* create(int *arr, Node* root, int i, int n)
{

    if (i < n)
    {
        Node* temp = newNode(arr[i]);
        root = temp;

        root->left = create(arr, root->left, 2 * i + 1, n);

        root->right = create(arr, root->right, 2 * i + 2, n);
    }
    return root;
}


void inorder(Node* root)                                  //Inorder Traversal
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}


void preorder(Node* root)                                      // Preorder Traversal
{
    if (root != NULL)
    {

        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node* root)                                // Postorder Traversal
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}


stack<int> s1;

void levels(Node *root)                                  // Finds level of each Node using Stacks
{
    if(root!=NULL) 
    {
        s1.push(root->data);
        levels(root->left);
        levels(root->right);

        cout << "Level of " << s1.top() << " = " << s1.size() << "\n";
        s1.pop();

    }
}


int main()
{
    int n;
    cout << "Enter no of elements:\n";
    cin >> n;

    int *a = new int[n];
    cout << "Enter node elements:\n";

    for(int i = 0;i < n;i++)
        cin >> a[i];

    Node* root = create(a, root, 0, n);

    cout << "\n\nInorder Traversal:\n";
    inorder(root);

    cout << "\n\nPreorder Traversal:\n";
    preorder(root);

    cout << "\n\nPostorder Traversal:\n";
    postorder(root);

    cout << "\n\n";

    levels(root);

    return 0;
}
