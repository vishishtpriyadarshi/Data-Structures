//
// Created by Vishisht Priyadarshi on 30-08-2019.
//

#include <iostream>

using namespace std;

struct Node
{
    int a;
    Node *next;
    Node *prev;
};

// *******************************************
//         Class Specifications
// *******************************************


class LinkedList
{
    Node *head;
    Node *tail;
    public:

        LinkedList();                        // Constructor

        int insertBegin(int e);              // Inserts an element at the beginning

        int insertRand(int e, int pos);      // Inserts an element at any Random specified position
        
        int insertLast(int e);               // Inserts an element at the end of List
    
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
    head = NULL;                             // initialises head of the List
    tail = NULL;	
}

int LinkedList::insertBegin(int e)
{
    Node *newNode = new Node;

    if(newNode == NULL)                    // If Creation of Node fails
        return -1;

    newNode->next = head;
    newNode->prev = NULL;
    head = newNode;

    newNode->a = e;

    return 1;                                 // Flag = 1 shows success of the operation
}


int LinkedList::insertRand(int e, int pos)
{
    Node *newNode = new Node;

    if(newNode == NULL)                     // If Creation of Node fails
        return -1;

    if(pos == 1)                               // Insertion at the Beginning
        return insertBegin(e);

    newNode->a = e;
    Node *curr = head->next;
    int pn = 1;

    while(curr != NULL)
    {
        pn++;
        if(pn == pos)                           // Found the position
        {
            curr->prev->next = newNode;
            newNode->prev = curr->prev;
	    newNode->next = curr;
            curr->prev = newNode;
           

            return 1;
        }
        curr = curr->next;
    }

    return 0;                                    // Flag = 0 shows unable to find the specified position
}


int LinkedList::insertLast(int e)
{
    Node *newNode = new Node;

    if(newNode == NULL)                    // If Creation of Node fails
        return -1;

    newNode->a = e;
    Node *curr = head;

    while(curr != NULL)
    {

        if(curr->next == NULL)              // Found the position
        {
            curr->next = newNode;
	    newNode->prev= curr;
            newNode->next = NULL;

            return 1;
        }
        curr = curr->next;
    }

    return 0;                                    // Flag = 0 shows unable to find the specified position

}


int LinkedList::deleteBegin()
{
    if(head == NULL)                          // Empty List
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

    int l = 0;

    if(head == NULL)                          // Empty List
        return -1;

    while(curr!=NULL)
    {
        l++;

        if(l == pos)                             // Found the position
        {
            if(curr->prev == NULL)                  // Deletion at the Beginning
                deleteBegin();

            curr->prev->next = curr->next;
            delete curr;

            return 1;
        }
        curr = curr->next;
    }

    return 0;
}


bool LinkedList::search(int e)
{
   if(head == NULL)                            // Empty List
       return 0;

   Node *n = head;
   while(n != NULL)
   {
       if(n->a == e)
            return 1;

       n = n->next;
   }

   return 0;

}

int LinkedList::length(){
    Node *node = head;

    if(head == NULL)
        return 0;

    int l = 0;

    while(node != NULL)
    {
        l++;
        node = node->next;
    }
    cout << "\n" << l << "\n";
    return l;
}

void LinkedList::elements()
{
    Node *node = head;

    if(head == NULL)
        return;

    while(node != NULL)
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

    cout << "******************MENU****************************\n\n";
    cout << "1. Insert an Element at beginning\n2. Insert an Element at Last\n3. Insert an Element at Random Position\n4. Delete from Beginning\n5. Delete at Specified position\n6. Search for an Element\n7. Print the List\n8. Print length of List\n0. Terminate \n\n";

    int a = 1;
    int e,pos;
    while( a!=0 ){
    cin >> a;
    switch(a)
    {
	case 1: 	
		cin >> e;
		list.insertBegin(e);
		break;
	case 2: 	
		cin >> e;
		list.insertLast(e);
		break;
	case 3: 
		cin >> e;
                cin >> pos;
		list.insertRand(e, pos);
		break;
	case 4: 
		list.deleteBegin();
		break;
	case 5: 
                cin >> pos;
		list.deleteRand(pos);
		break;
	case 6: 
		cin >> e;
		list.search(e);
		break;
	case 7: 
		list.elements();
		break;
	case 8:
		 list.length();
		break;
        case 0:
		 cout << "Terminated\n";
      }
      }
        

    return 0;

}
