#include "bits/stdc++.h"
using namespace std;


int ct = 0;                                 // For Queue
struct node
{
    int data;
    int d;
    node* pred;
    string col;
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


void adjList(node **a, int l)
{
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
}


int find(node *vert, int data, int l)
{
    for(int i = 0; i < l; i++)
    {
        if(vert[i].data == data)
            return i;
    }
}

// ************* QUEUE **************************

void push(node *Q, int l, int data)
{
    Q[ct++].data = data;
}

void pop(node *Q, int l)
{
    ct--;
}

node front(node *Q, int l)
{
    return Q[0];
}

// ***********************************************


void BFS(node *vert, node **a, int l, int s)
{
    node *st = a[s]->next;
    
    for(int i = 0; i < l; i++)
    {
        vert[i].col = "white";
        vert[i].d = INT_MAX;
        vert[i].pred = NULL;
    }
    
    vert[s].col = "gray";
    vert[s].d = 0;
    
    node *Q = new node[l];
    
    push(Q, l, vert[s]);
   
    while(ct != 0)                  // while (Queue Not empty)
    {
        node u = front(Q, l);
        pop(Q, l);
        
        node *adj = a[find(vert, u.data, l)]->next;
        
        while(adj != NULL)
        {
            if(adj->col == "white")
            {
              
                int i = find(vert, adj->data, l);
                vert[i].col = "gray";
                vert[i].d = u.d + 1;
                vert[i].pred = u;
                
                push(Q, l, vert[i]);
                }
                // Updation complete
                
            }
            adj = adj->next;
        }
      
        u.col = "black";
       
    }
    
    
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
   
    // ***********************************
   
    node *vert = new node[l];
   
    for(int i = 0; i < l; i++)
    {
       vert[i]->data = a[i]->next->data; 
    }
   
   
    BFS(vert, a, l, 1);
   
    for(int i = 0; i < l; i++)
        cout << "Data = " <<  vert[i]->data << "   Distance = " << vert[i]->d << "    Color = " << vert[i]->col << endl;
   
   
 

    return 0;
}
