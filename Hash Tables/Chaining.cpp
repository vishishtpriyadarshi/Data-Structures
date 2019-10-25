#include <bits/stdc++.h>
#define si 50

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

int hashValue(string key)
{
    int n = key.length();
    int h = 0;
    
    for(int i = 0; i < n; i++)
       h += key[i]*pow(p,i); 
       
    return h%m;
}


void insert(node **add, string key, int value)
{
    int h = hashValue(key) % si;
    
    node* nxt = add[h];
    if(nxt == NULL)
        add[h] = nxt;
    else
    {
        while(nxt->ptr != NULL)
            nxt = nxt->ptr;
        
        nxt->ptr = create(value);
    }
    
   
    
}


void print(node **add)
{
    for(int i = 0; i < si; i++)
    {
        node *next = add[i];
        if(next == NULL)
        {
            cout << "llow\n";
            continue;
        }
        else
        {
            while(next != NULL)
            {
                cout << next->data << " -> ";
                next = next->ptr;
            }
            cout << "\n";
        }
        
    }
}

int main()
{
    node **add = new node*[si];
    for(int i = 0; i < si; i++)
        add[i] = NULL;
        
    cout << "Enter Key - Value pairs\nPress STOP -1 to STOP\n\n";
    string k;
    int v;
    cin >> k >> v;
    
    while(k != "STOP" && v != -1)
    {
        insert(add, k, v);
        cin >> k >> v;
    }
    
    print(add);
    return 0;
}
