#include <bits/stdc++.h>
#define si 10
#define m 1000000009
#define p 31

using namespace std;

struct node
{
    int data;
    string key;
    node *ptr;
};

node *create(int d, string key)
{
    node *n = new node;
    n->data = d;
    n->key = key;
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
        add[h] = create(value, key);
    else
    {
        while(nxt->ptr != NULL)
        {
            if(nxt->key == key)
            {
                nxt->data = value;
                return;
            }
            nxt = nxt->ptr;
        }
            
        
        nxt->ptr = create(value, key);
    }
    
   
    
}


void print(node **add)
{
    cout << "\n*************************\n\n";
    for(int i = 0; i < si; i++)
    {
        node *next = add[i];
        if(next == NULL)
        {
            //cout << "llow\n";
            continue;
        }
        else
        {
            while(next != NULL)
            {
                cout << "[ " << next->key << " = " << next->data << " ] -> ";
                next = next->ptr;
            }
            cout << "\b\b  \n";
        }
        
    }
    cout << "\n*************************\n\n";
}


bool isPresent(node **a, string key)
{
    for(int i = 0; i < si; i++)
    {
        node *curr = a[i];
        while(curr != NULL)
        {
            if(curr->key == key)
                return true;
            curr = curr->ptr;
        }
    }
    
    return false;
}


void removeKey(node **add, string key)
{
    int h = hashValue(key) % si;
    node* nxt = add[h];
    
    if(nxt->key == key)
    {
        if(nxt->ptr != NULL)
            add[h] = nxt->ptr;
        else
            add[h] = NULL;
    }
    else
    {
        while(nxt != NULL && nxt->ptr != NULL)
        {
            if(nxt->ptr->key == key)
            {
                nxt->ptr = nxt->ptr->ptr;
                return;
            }
            
            nxt = nxt->ptr;
        }
    }
    
}

int main()
{
    node **add = new node*[si];
    for(int i = 0; i < si; i++)
        add[i] = NULL;
        
    cout << "Enter Key - Value pairs\nPress \"STOP -1\" to Terminate\n\n";
    string k;
    int v;
    
    cout << "**************** MENU *********************\n1: Insert\n2: Check Existence of A Key-Value\n3: Remove a Key-Value Pair\n4: Print the Hash Table\n0: TERMINATE\n\n";
    int choice;
    cin >> choice;
    
    while(choice != 0)
    {
        switch(choice)
        {
        case 1: cin >> k >> v;
                insert(add, k, v);
                break;
                
        case 2: cin >> k;
                if(isPresent(add, k)) cout << "Value Exists in the Table\n\n";
                else cout << "Value Doesn't Exist in the Table\n\n";
                break;
                
        case 3: cin >> k;
                if(isPresent(add,k))
                {
                    removeKey(add, k);
                    cout << "Key Removed\n\n";
                }
                else
                    cout << "Key Doesn't Exist\n\n";
                    
                break;
                
        case 4: print(add);
                break;
                
        case 0: cout << "TERMINATED.....";
                break;
        }
                
        //cout << "**************** MENU *********************\n1: Insert\n2: Check Existence of A Key-Value\n3: Remove a Key-Value Pair\n4: Print the Hash Table\n0: TERMINATE\n\n";
        cin >> choice;
                
    }
    
    
    return 0;
}
