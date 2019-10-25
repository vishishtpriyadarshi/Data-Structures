#include <bits/stdc++.h>
#include size 50

#define m 1000000009
#define p 31

using namespace std;

struct node
{
    int data;
    node *ptr;
};

node *create(int d)
{
    node *n = new node;
    n->data = d;
    n->ptr = NULL;
}

int hash(string key)
{
    int n = key.length();
    int h = 0;
    
    for(int i = 0; i < n; i++)
       h += key[i]*pow(p,i); 
       
    return h%m;
}


void add(int **add, string key, int value)
{
    int h = hash(string)%size;
    
    node* nxt = add[h];
    
    while(nxt->ptr != NULL)
        nxt = nxt->ptr;
        
    nxt->ptr = create(value);
    
}


int main()
{
    printf("Hello World!\n");
    return 0;
}
