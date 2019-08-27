//
// Created by Vishisht Priyadarshi on 26-08-2019.
//

#include <iostream>

using namespace std;

struct Node
{
    int a;
    Node *next;
};

// *******************************************
//         Class Specifications
// *******************************************


class LinkedList
{
    Node *head;
    public:

        LinkedList();                        // Constructor

        int insertBegin(int e);              // Inserts an element at the beginning

        int insertRand(int e, int pos);      // Inserts an element at any Random specified position

        int deleteBegin();                   // Deletes an element from beginning

        int deleteRand(int pos);             // Deletes an elememt from any random specified position

        bool search(int e);                  // Search an element

        int length();                        // Find the number of nodes in the List

        void elements();                     // Prints the value contained in each of the nodes
};


// ********************************************
//            Member Functions
// ********************************************


LinkedList::LinkedList()
{
    head = nullptr;                          // initialises head of the List
}


int LinkedList::insertBegin(int e)
{
    Node *newNode = new Node;

    if(newNode == nullptr)                    // If Creation of Node fails
        return -1;

    newNode->next = head;
    head = newNode;

    newNode->a = e;

    return 1;                                 // Flag = 1 shows success of the operation
}


int LinkedList::insertRand(int e, int pos)
{
    Node *newNode = new Node;

    if(newNode == nullptr)                     // If Creation of Node fails
        return -1;

    if(pos == 1)                               // Insertion at the Beginning
        return insertBegin(e);

    newNode->a = e;
    Node *curr = head->next;
    Node *prev = head;
    int pn = 1;

    while(curr != nullptr)
    {
        pn++;
        if(pn == pos)                           // Found the position
        {
            prev->next = newNode;
            newNode->next = curr;

            return 1;
        }
        curr = curr->next;
        prev = prev->next;
    }

    return 0;                                    // Flag = 0 shows unable to find the specified position
}


int LinkedList::deleteBegin()
{
    if(head == nullptr)                          // Empty List
        return -1;

    Node *del = head;
    head = head->next;
    delete del;

    return 1;
}


int LinkedList::deleteRand(int pos)
{
    Node *node = head;

    Node *curr = head;
    Node *prev = nullptr;

    int l = 0;

    if(head == nullptr)                          // Empty List
        return -1;

    while(curr!=nullptr)
    {
        l++;

        if(l == pos)                             // Found the position
        {
            if(prev == nullptr)                  // Deletion at the Beginning
                deleteBegin();

            prev->next = curr->next;
            delete curr;

            return 1;
        }
        prev = curr;
        curr = curr->next;
    }

    return 0;
}


bool LinkedList::search(int e)
{
   if(head == nullptr)                            // Empty List
       return 0;

   Node *n = head;
   while(n != nullptr)
   {
       if(n->a == e)
            return 1;

       n = n->next;
   }

   return 0;

}

int LinkedList::length(){
    Node *node = head;

    if(head == nullptr)
        return 0;

    int l = 0;

    while(node != nullptr)
    {
        l++;
        node = node->next;
    }
    return l;
}

void LinkedList::elements()
{
    Node *node = head;

    if(head == nullptr)
        return;

    while(node != nullptr)
    {
        cout << node->a << " ";
        node = node->next;
    }
    cout << "\n";
}

// **********************************
//          Main Function
// **********************************


int main()
{
    LinkedList list;                               // Object Creation

    list.insertBegin(1);
    list.insertBegin(23);
    list.insertBegin(32);
    list.insertBegin(45);
    list.insertBegin(90);

    cout << list.deleteRand(5) << "\n\n";

    cout << list.length() << endl;
    cout << list.search(23) << endl;
    list.elements();
}
