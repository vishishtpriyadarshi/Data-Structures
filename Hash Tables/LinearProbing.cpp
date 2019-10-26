#include <bits/stdc++.h>
#define si 10
#define m 1000000009
#define p 31

using namespace std;

int *value = new int[si];
string *key = new string[si];
int *flag = new int[si];

int hashValue(string k)
{
    int hash, i;
    int len = k.length();
    
    for(hash = i = 0; i < len; ++i)
    {
        hash += k[i];
        hash += (hash << 10);
        hash ^= (hash >> 6);
    }
    hash += (hash << 3);
    hash ^= (hash >> 11);
    hash += (hash << 15);
    return hash;
}


void insert(string k, int v)
{
    int h = hashValue(k) % si;
    
    int i = 0;
    while(1)
    {
        if(value[h] == -1 || flag[h] == 1)      // ISSUE: || k.compare(key[h]) == 0)
        {
            value[h] = v;
            key[h] = k;
            return;
        }
        else
            h = (h + (i++)) % si;
            
    }
}


void print()
{
    cout << "\n*************************\n\n";
    for(int i = 0; i < si; i++)
    {
        if(flag[i] != 1)
        {
            if(value[i] == -1)
                cout << "NULL\n";
            else
                cout << key[i] << " = " << value[i] << "\n";
        }
        
    }
    cout << "\n*************************\n\n";
}


bool isPresent(string k)
{
    int i = 0;
    int h = hashValue(k) % si;
    
    while(i < si)
    {
        if(key[i] == k)
            return true;
        else
            h = (h + (i++)) % si;
            
    }
    return false;
}


void removeKey(string k)            // ISSUE : INFINITE LOOP
{
    int h = hashValue(k) % si;
    
    int i = 0;
    if(isPresent(k))
    {
        while(1)
        {
            if(key[h] == k)
                flag[h] == 1;
            else
                h = (h + (i++)) % si;
                
        }
    }
    else
        cout << "Key Not Present\n\n";
    
}

int main()
{
    
    for(int i = 0; i < si; i++)
    {
        value[i] = -1;
        key[i] = "";
        flag[i] = -1;
    }
        
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
                insert(k, v);
                break;
                
        case 2: cin >> k;
                if(isPresent(k)) cout << "Value Exists in the Table\n\n";
                else cout << "Value Doesn't Exist in the Table\n\n";
                break;
                
        case 3: cin >> k;
                if(isPresent(k))
                {
                    removeKey(k);
                    cout << "Key Removed\n\n";
                }
                else
                    cout << "Key Doesn't Exist\n\n";
                    
                break;
                
        case 4: print();
                break;
                
        case 0: cout << "TERMINATED.....";
                break;
        }
                
        //cout << "**************** MENU *********************\n1: Insert\n2: Check Existence of A Key-Value\n3: Remove a Key-Value Pair\n4: Print the Hash Table\n0: TERMINATE\n\n";
        cin >> choice;
                
    }
    
    
    return 0;
}
