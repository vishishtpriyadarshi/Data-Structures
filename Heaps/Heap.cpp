//
// Created by Vishisht Priyadarshi on 11-09-2019.
//

#include <iostream>
#include <bits/stdc++.h>
#include <math.h>

using namespace std;


int n;                                   // Size of Heap
void maxHeapify(int *arr, int i)
{
    int l = 2*i + 1;                     // Left Child
    int r = 2*i + 2;                     // Right Child
    
    int largest = 0;
    
    if(l < n && arr[l] > arr[i])
        largest = l;
    else
        largest = i;
    
    if(r < n && arr[r] > arr[largest])
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
  for(int i = n/2 + 1; i >= 0; i--)
    maxHeapify(arr, i);
}


void deleteMax(int *a)
{
    a[0] = a[n-1];
    n--;
    
    buildMaxHeap(a);
}



int main()
{
    cout << "Enter no of elements:\n";
    cin >> n;

    int *a = new int[n];
    cout << "Enter node elements:\n";

    for(int i = 0;i < n;i++)
        cin >> a[i];

    

    buildMaxHeap(a);
    
    cout << "Heap stored in array:\n";
    for(int i = 0; i<n; i++)
    {
        if(ceil(log2(i+1)) == floor(log2(i+1)))   // sends each new level to new line
            cout << "\n";
    
        cout << a[i] << " ";
    }
        
        
        
    deleteMax(a);
    
    cout << "\nAfter Deletion:\n";
    
    
    for(int i = 0; i<n; i++)
    {
        if(ceil(log2(i+1)) == floor(log2(i+1)))
            cout << "\n";
        
        cout << a[i] << " ";
        
    }
    return 0;
}
