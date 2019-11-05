//
// Created by Vishisht Priyadarshi on 04-11-2019.
//

#include <bits/stdc++.h>
#include <stdio.h>
#define COUNT 10

using namespace std;

struct node
{
    int key;
    node *right;
    node *left;
    node *parent;
};

node *create()
{
    node *n = new node;
    n->key = -1;
    n->right = NULL;
    n->left = NULL;
    n->parent = NULL;

    return n;
}



// ============================
// Finds the node
// ============================
node* n = create();                 // A variable to store the nodes found corresponding to find() function
node* find(node *root, int key)     // If key is not available, it returns the last visited node
{
    if(root != NULL)
    {
        n = root;
        if(root->key < key)
            find(root->right, key);
        else if(root->key > key)
            find(root->left, key);
    }

    return n;
}




// ===============================
// Inserrtion of Nodes in BST
// ===============================
void add(node *root, int key)
{
    if(root != NULL)
    {
        node *par = find(root, key);

        if(par->key > key)
        {
            par->left = create();
            par->left->key = key;
            par->left->parent = par;
        }
        else if(par->key < key)
        {
            par->right = create();
            par->right->key = key;
            par->right->parent = par;
        }
    }
    else
    {
        root = create();
        root->key = key;
        root->parent = root;
        //cout << "HI";
    }
}


// ======================
// Inorder Traversal
// ======================
void inorder(node *root)
{
    if(root != NULL)
    {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);

    }
}


// ================================
// Minimum & Maximum keys in BST
// ================================

node* minimum(node *root)
{
    while(root->left != NULL)
    {
        root = root->left;
    }

    return root;
}


node* maximum(node *root)
{
    while(root->right != NULL)
    {
        root = root->right;
    }

    return root;
}


// ===========================================
// Successor and Predecessor of a Given Node
// ===========================================

node *successor(node *root)
{
    if(root->right != NULL)
        return minimum(root->right);
    else
    {
        while(root->parent != NULL)             // Traverse upwards till reaches at the top of BST
        {
            root = root->parent;
            if(root->parent != NULL)
            {
                if(root == root->parent->left)
                    return root;                // Current node is the left child
            }
        }
        return root;
    }
}

node *predecessor(node *root)
{
    if(root->left != NULL)
        return maximum(root->left);
    else
    {
        while(root->parent != NULL)             // Traverse upwards till reaches at the top of BST
        {
            root = root->parent;
            if(root->parent != NULL)
            {
                if(root == root->parent->right) // Current node is the right child
                    return root;
            }
        }
        return root;
    }
}



// ============================================
// 2D Printing of a BST
// ============================================

void print2DUtil(node *root, int space)
{
    // Base case
    if (root == NULL)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    print2DUtil(root->right, space);

    // Print current node after space
    // count
    cout<<endl;
    for (int i = COUNT; i < space; i++)
        cout<<" ";
    cout<<root->key<<"\n";

    // Process left child
    print2DUtil(root->left, space);
}


void printBST(node *root)
{
    // Pass initial space count as 0
    print2DUtil(root, 0);
}




// ===========================================================================
// Exchanges the initial and final nodes but their child nodes aren't handled
// ===========================================================================

void Transplant(node *root, node *initial, node *final)
{
    if(final->parent->left == final)
        final->parent->left = NULL;
    else
        final->parent->right = NULL;


    if(initial->parent == NULL) {                           // If Node to be deleted is the Root Node
        root->key = final->key;
        final->left = initial->left;
        root->right = final->right;

    }
    else if(initial == initial->parent->left)
        initial->parent->left = final;
    else if(initial == initial->parent->right)
        initial->parent->right = final;

}

// ==============================================
// Node Deletion
// ==============================================

void deleteNode(node *root, node *delNode)
{
    if(delNode->left == NULL && delNode->right == NULL)         // CASE 1: delNode has no children
    {
        if(delNode->parent->left == delNode)
            delNode->parent->left = NULL;
        else
            delNode->parent->right = NULL;
    }
    else if(delNode->left == NULL || delNode->right == NULL)    // CASE 2: delNode has 1 child only
    {
        if(delNode->left != NULL)                               // Point parent of delNode to child of delNode and vice-versa
        {
            if(delNode->parent->left == delNode)
                delNode->parent->left = delNode->left;
            else
                delNode->parent->right = delNode->left;
        }
        else
        {
            if(delNode->parent->left == delNode)
                delNode->parent->left = delNode->right;
            else
                delNode->parent->right = delNode->right;
        }
    }
    else                                                       // CASE 3: delNode has both children
    {
        node *y = successor(delNode);
        //cout << "\n\n" << y-> key << "\n\n";
        if(y->left == NULL && y->right == NULL)                // CASE 3.(a) : Successsor has no child
        {
            Transplant(root, delNode, y);
            y->right = delNode->right;
            y->left = delNode->left;
        }
        else                                                   // CASE 3.(b) : Successor has 1 child (THESE ARE THE ONLY CASES
        {                                                      //                2 Children of successor isn't possible)
            node *temp = delNode;
            /*if(y == delNode->parent->left)
            {
                delNode->parent->left = y;
                if(y->right == NULL)
                    y->right = delNode->right;
                else
                    y->left = delNode->right;
            }
            else{
                delNode->parent->right = y;
                if (y->right == NULL)
                    y->right = delNode->left;
                else
                    y->left = delNode->left;
            }*/

            /*if(y->right != NULL)
            {
                Transplant(root, y, y->right);
            }
            else
                Transplant(root, y, y->left);*/

            Transplant(root, delNode, y);           // Replaces the node to be deleted with its successor
            //y->right = delNode->right;
            //y->left = temp->left;
            y->left = delNode->left;                // As Successor will always be in right subtree and left one needs to be joined to it

            cout << "\\n\nYEAH\n\n";


        }

    }

}

// =====================================
// MAIN METHOD
// =====================================
int main()
{
    node *root = create();
    /*root->key = 15;
    root->parent = NULL;
    add(root, 15);
    add(root, 5);
    add(root, 3);
    add(root, 12);
    add(root, 10);
    add(root, 13);
    add(root, 6);
    add(root, 7);
    add(root, 16);
    add(root, 20);
    add(root, 18);
    add(root, 23);
    add(root, 14);


    // SOME QUERIES

    cout << "\n\nMinimum = " << minimum(root)->key;
    cout << "\n\nSuccessor = " << successor(find(root, 15))->key;
    deleteNode(root, find(root,12));
    printBST(root);
    cout << "\n";
    inorder(root);*/

    cout << "********** MENU **********:\n\n";
    cout << "1.     ADD x           -> Inserts node with value = x\n";
    cout << "2.     DEL x           -> Deletes node with value = x\n";
    cout << "3.     SUCCESSOR x     -> Finds successor of x\n";
    cout << "4.     PREDECESSOR x   -> Finds predecessor of x\n";
    cout << "5.     MAX             -> Finds maximum value in BST\n";
    cout << "6.     MIN             -> Finds minimum valur in BST\n";
    cout << "7.     INORDER         -> Prints Inorder Traversal\n";
    cout << "8.     PRINT2D         -> Prints BST in 2D Form\n";
    cout << "9.     EXISTS x        -> Checks if x exists in BST\n";
    cout << "10.    MENU            -> Prints Menu\n";
    cout << "11.    EXIT            -> Exits the MENU\n\n";

    string str;
    cin >> str;

    int i = 0;
    while(str != "EXIT")
    {
        if(str == "ADD")
        {
            int x;
            cin >> x;
            if(i == 0) {
                root->key = x;
                root->parent = NULL;
                i++;
            }
            else
                add(root, x);
        }
        else if(str == "DEL")
        {
            int x;
            cin >> x;
            if(x == find(root, x)->key)
                deleteNode(root, find(root,x));
            else
                cout << "\nValue doesn't exist in the BST\n";
        }
        else if(str == "SUCCESSOR")
        {
            int x;
            cin >> x;
            if(x == find(root, x)->key)
            {
                if(successor(find(root, x))->parent == NULL)
                    cout << "\nDoesnt Exist\n";
                else
                    cout << "\n" << successor(find(root,x))->key << "\n";
            } else
                cout << "\nValue doesn't exists in the BST\n";

        }
        else if(str == "PREDECESSOR")
        {
            int x;
            cin >> x;
            if(x == find(root, x)->key)
            {
                if(predecessor(find(root, x))->parent == NULL)
                    cout << "\nDoesnt Exist\n";
                else
                    cout << "\n" << predecessor(find(root,x))->key << "\n";
            } else
                cout << "\nValue doesn't exists in the BST\n";

        }
        else if(str == "MAX")
            cout << "Mximum Value = " << maximum(root)->key << "\n";
        else if(str == "MIN")
            cout << "Minimum Value = " << minimum(root)->key << "\n";
        else if(str == "INORDER") {
            inorder(root);
            cout << "\n\n";
        }
        else if(str == "PRINT2D")
            printBST(root);
        else if(str == "MENU")
        {
            cout << "********** MENU **********:\n\n";
            cout << "1.     ADD x           -> Inserts node with value = x\n";
            cout << "2.     DEL x           -> Deletes node with value = x\n";
            cout << "3.     SUCCESSOR x     -> Finds successor of x\n";
            cout << "4.     PREDECESSOR x   -> Finds predecessor of x\n";
            cout << "5.     MAX             -> Finds maximum value in BST\n";
            cout << "6.     MIN             -> Finds minimum valur in BST\n";
            cout << "7.     INORDER         -> Prints Inorder Traversal\n";
            cout << "8.     PRINT2D         -> Prints BST in 2D Form\n";
            cout << "9.     EXISTS x        -> Checks if x exists in BST\n";
            cout << "10.    MENU            -> Prints Menu\n";
            cout << "11.    EXIT            -> Exits the MENU\n\n";
        }
        else if(str == "EXISTS")
        {
            int x;
            cin >> x;
            if(x == find(root, x)->key)
                cout << "\nValue exists in BST\n";
            else
                cout << "\nValue doesn't exist in BST\n";
        }
        else
        {
            cout << "\nWrong INPUT\n\n";
            cout << "********** MENU **********:\n\n";
            cout << "1.     ADD x           -> Inserts node with value = x\n";
            cout << "2.     DEL x           -> Deletes node with value = x\n";
            cout << "3.     SUCCESSOR x     -> Finds successor of x\n";
            cout << "4.     PREDECESSOR x   -> Finds predecessor of x\n";
            cout << "5.     MAX             -> Finds maximum value in BST\n";
            cout << "6.     MIN             -> Finds minimum valur in BST\n";
            cout << "7.     INORDER         -> Prints Inorder Traversal\n";
            cout << "8.     PRINT2D         -> Prints BST in 2D Form\n";
            cout << "9.     EXISTS x        -> Checks if x exists in BST\n";
            cout << "10.    MENU            -> Prints Menu\n";
            cout << "11.    EXIT            -> Exits the MENU\n\n";
        }
        cin >> str;
    }
    
    return 0;
}


