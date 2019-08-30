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

int i = 0;                            // Indicator Variable


// *******************************************
//         Class Specifications
// *******************************************


class LinkedList
{
  Node *head;
  Node *tail;
  Node *sentinel;
  
public:
  
  LinkedList();                        // Constructor
  
  void initialise();                   // Initialise the list with sentinel
  
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
  sentinel = new Node;
  head = sentinel;                                 // initialises head of the List
  tail = sentinel;	
}

void LinkedList::initialise()
{
  
  sentinel->a = -1;
  sentinel->next = sentinel;
  sentinel->prev = sentinel;
  
  
  
}
int LinkedList::insertBegin(int e)
{
  Node *newNode = new Node;
  
  if(newNode == NULL)                           // If Creation of Node fails
    return -1;
  
  newNode->next = sentinel->next;
  sentinel->next->prev = newNode;
  newNode->prev = sentinel;
  
  sentinel->next = newNode;
  
  newNode->a = e;
  
  if(i == 0)
  {
    tail = newNode;
  }
  
  return 1;                                    // Flag = 1 shows success of the operation
}


int LinkedList::insertRand(int e, int pos)
{
  Node *newNode = new Node;
  
  if(newNode == NULL)                         // If Creation of Node fails
    return -1;
  
  if(pos == 1)                               // Insertion at the Beginning
    return insertBegin(e);
  
  newNode->a = e;
  Node *curr = sentinel->next;
  
  int pn = 0;
  
  while(curr != sentinel)
  {
    pn++;
    if(pn == pos)                           // Found the position
    {
      curr->prev->next = newNode;
      newNode->prev = curr->prev;
      newNode->next = curr;
      curr->prev = newNode;
      
      if(newNode->next == sentinel)
        tail = newNode;
      
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
  Node *curr = sentinel->next;
  
  while(curr != sentinel)
  {
    
    if(curr->next == sentinel)              // Found the position
    {
      curr->next = newNode;
      newNode->prev= curr;
      newNode->next = sentinel;
      sentinel->prev = newNode;
      
      tail = newNode;
      
      return 1;
    }
    curr = curr->next;
  }
  
  return 0;                                    // Flag = 0 shows unable to find the specified position
  
}


int LinkedList::deleteBegin()
{
  
  Node *del = sentinel->next;
  sentinel->next = del->next;
  del->next->prev = sentinel;
  
  delete del;
  
  
  return 1;
}


int LinkedList::deleteRand(int pos)
{
 
  Node *curr = sentinel->next;
  
  int l = 0;
  
  
  while(curr!=sentinel)
  {
    l++;
    
    if(l == pos)                             // Found the position
    {
      if(curr->prev == sentinel)                  // Deletion at the Beginning
        return deleteBegin();
      
      curr->prev->next = curr->next;
      
      if(curr->next == sentinel)
        tail = curr->prev;
      
      delete curr;
      
    
      return 1;
    }
    curr = curr->next;
  }
  
  return 0;
}


bool LinkedList::search(int e)
{
  
  
  Node *n = sentinel->next;
  while(n != sentinel)
  {
    if(n->a == e)
      return 1;
    
    n = n->next;
  }
  
  return 0;
  
}

int LinkedList::length(){
  Node *node = sentinel->next;
  
  int l = 0;
  
  while(node != sentinel)
  {
    l++;
    node = node->next;
  }
  cout << "Length = " << l << "\n";
  return 1;
}

void LinkedList::elements()
{
  Node *node = sentinel->next;
  
  
  while(node != sentinel)
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
  list.initialise();
  
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
      cout << "Success code = " << list.insertBegin(e) << "\n";
      break;
    case 2: 	
      cin >> e;
      cout << "Success code = " <<  list.insertLast(e) << "\n";
      break;
    case 3: 
      cin >> e;
      cin >> pos;
      cout << "Success code = " << list.insertRand(e, pos) << "\n";
      break;
    case 4: 
      cout << "Success code = " << list.deleteBegin() << "\n";
      break;
    case 5: 
      cin >> pos;
      cout << "Success code = " << list.deleteRand(pos) << "\n";
      break;
    case 6: 
      cin >> e;
      cout << "Success code for Search = " << list.search(e) << "\n";
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
