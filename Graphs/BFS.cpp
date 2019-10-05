#include "bits/stdc++.h"
using namespace std;

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



void BFS(node **a, int start, int l)
{
    node *s = a[start]->next;
    for(int i = 0; i < l; i++)
    {
       node *curr = a[i]->next;
       //cout << "\nVertex " << i << " => ";
       while(curr != NULL)
       {
            curr->col = "white";
            curr->d = 0;
            curr->pred = NULL;
            curr = curr->next;
       }
       
       
    }
    for(int i = 0; i < l ; i++)
    {
        node *curr = a[i]->next;
        while(curr != NULL)
        {
            if(curr->data == s->data)
            {
                curr->col = "gray";
                curr->d = 0;
                curr->pred = NULL;
             }
             curr = curr->next;
        }
    }
   s->col = "gray";
   s->d = 0;
   s->pred = NULL;
   queue<node*> Q;
   
   Q.push(s);
   
   while(!Q.empty())
   {
      node* u = Q.front();
      Q.pop();
       
      
      node *adj = u->next;
      
      while(adj != NULL)
      {
          if(adj->col == "white")
          {
              
              // Updating each occurrence of vertex in list representation 
              for(int i = 0; i < l ; i++)
              {
                  node *curr = a[i]->next;
                  while(curr != NULL)
                  {
                    if(curr->data == adj->data)
                    {
                        curr->col = "gray";
                        curr->d = u->d + 1;
                        curr->pred = u;
                        
                       
                        //Q.push(a[adj->data]->next);
                    }
                    curr = curr->next;
                  }
                  Q.push(a[adj->data]->next);
              }
              // Updation complete
                
          }
          adj = adj->next;
      }
      
      u->col = "black";
       
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
        a[i]->next = create(i);
   }
   
   cout <<"Enter edges and PRESS -1 FOR EACH VERTEX TO TERMINATE:\n";
   
   int u,v;
   cin >> u >> v;
   
   while(u != -1 && v!= -1)
   {
       add(u,v,a);
       cin >> u >> v;
   }
   
   BFS(a,1,l);
   
   for(int i = 0; i < l; i++)
   {
       node *curr = a[i]->next;
       cout << "\nVertex " << i << " =>\n";
       while(curr != NULL)
       {
            cout << "Data = " <<  curr->data << "   Distance = " << curr->d << "    Color = " << curr->col << endl;
            curr = curr->next;
       }
       
       cout << "\n\n ************************************** \n\n";
       
       /*while(curr != NULL)
       {
            cout << curr->data << "->";
            curr = curr->next;
       }
       
       cout << "\b \b\b  \n";*/
   }
 

    return 0;
}
