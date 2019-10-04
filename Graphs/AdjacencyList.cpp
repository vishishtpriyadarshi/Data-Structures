#include "bits/stdc++.h"
using namespace std;

struct node
{
    int data;
    node* next;
};

node* create(int d)
{
    node *n = new node;
    n->data = d;
    n->next = NULL;
}


void add(int u, int v, node** a)               // Creates Adjacency List
{
    node* n1 = a[u];
    while(n1->next != NULL)
        n1 = n1->next;
    
    n1->next = create(v);
    
    
    node* n2 = a[v];
    while(n2->next != NULL)
        n2 = n2->next;
        
    n2->next = create(u);
}


int main()
{
   cout << "Enter no of vertices:\n";
   int l;
   cin >> l;
   
   node **a = new node*[l];                       // Array of Pointers to Linked Lists
   for(int i = 0; i < l; i++)
        a[i] = new node;                          // Initialising each array pointer element to avoid " Segmentation Fault "
        
   for(int i = 0; i < l; ++i)
   {
        a[i]->data = -1;
        a[i]->next = NULL;
   }
   
   cout <<"Enter edges and PRESS -1 FOR EACH VERTEX TO TERMINATE:\n";
   
   int u,v;
   cin >> u >> v;
   
   while(u != -1 && v!= -1)
   {
       add(u,v,a);
       cin >> u >> v;
   }
   
   
   for(int i = 0; i < l; i++)
   {
       node *curr = a[i]->next;
       cout << "\nVertex " << i << " => ";
       while(curr != NULL)
       {
            cout << curr->data << "->";
            curr = curr->next;
       }
       
       cout << "\b \b\b  \n";
   }
 

    return 0;
}
