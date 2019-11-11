//
// Created by Vishisht Priyadarshi on 11-09-2019.
//

#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
# define size 50

using namespace std;


int n;                                   // Size of Dynamic Array
int ct;                                  // Size of Heap

void maxHeapify(int *arr, int i)
{
    int l = 2*i + 1;                     // Left Child
    int r = 2*i + 2;                     // Right Child
    
    int largest = 0;
    
    if(l < ct && arr[l] > arr[i])
        largest = l;
    else
        largest = i;
    
    if(r < ct && arr[r] > arr[largest])
        largest = r;
        
    if(largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        
        maxHeapify(arr, largest);
    }
}


void buildMaxHeap(int *arr)
{
  for(int i = n/2 - 1; i >= 0; i--)
    maxHeapify(arr, i);
}


void deleteMax(int *a)
{
    a[0] = a[ct-1];
    //n--;
    ct--;
    
    buildMaxHeap(a);
}



void printMax(int *a)
{
    cout << "\n\nMax element = " << a[0] << "\n";
}



void print(int *a)
{
    cout << "\n\n********  Heap  *********\n";
    for(int i = 0; i <= ct; i++)
    {
        if(ceil(log2(i+1)) == floor(log2(i+1)))
            cout << "\n";
        cout << a[i] << " ";
    }
}


void heapIncreaseKey(int *a, int i, int key)
{
    if(key < a[i])
    {
        cout << "*** NOT ALLOWED ***\nNEW KEY IS SMALLER THAN CURRENT VALUE.\n\n";
        return;
    }
    
    a[i] = key;
    
    while(i > 0 && a[i/2] < a[i])
    {
        int temp = a[i/2];
        a[i/2] = a[i];
        a[i] = temp;
        
        i = i/2;
    }
}


void insert(int *A, int key)
{
    ct++;
    A[ct] = -100;
    
    heapIncreaseKey(A, ct, key);
}


int main()
{
    int *A = new int[size];
    cout << "Enter elements:\n\n*****ENTER -1 TO STOP******\n\n\n";
    for(int i = 0; i < size; i++)
        A[i] = INT_MIN;

    n = size;                              // SIZE of the Array
    ct = -1;                               // Position of last inserted element
    
    int a;
    cin >> a;
    
    while(a != -1)
    {
        insert(A, a);
        cin >> a;
        
    }

    // ***** SOME OPERATIONS *******
    print(A);
    
    //cout << "\n" << A[ct];
    printMax(A);
    deleteMax(A);
    print(A);
    
    heapIncreaseKey(A, 3 , 91);
    print(A);
    
    deleteMax(A);
    deleteMax(A);
    
    print(A);
    
    return 0;
}
