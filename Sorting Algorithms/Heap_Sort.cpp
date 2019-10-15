//
// Created by Vishisht Priyadarshi on 25-09-2019.
//

#include <iostream>
#include <cmath>


using namespace std;

int n;                                  // Size of the Heap     

void swap(int* a, int* b)               // Swapping
{
    int t = *a;
    *a = *b;
    *b = t;
}


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


void Heap_Sort(int *a)
{
    buildMaxHeap(a);
    //cout << "After Build maxHeap:\n";
    int nodes = n;
    for(int i = nodes - 1; i >= 1; i--)
    {
        swap(&a[i], &a[0]);
        n--;
        maxHeapify(a, 0);
    }
}

void print(int *a)
{
    cout << "\n\nSorted Array:\n";
    for(int i = 0; i < n; i++)
        cout << a[i] << " ";
}

int main()
{
    cout << "Enter length :\n";
    cin >> n;
    
    int size = n;
    int *a = new int[n];

    for(int i = 0; i < n; i++)
        cin >> a[i];

    Heap_Sort(a);
    
    n = size;
    print(a);

    return 0;
}
