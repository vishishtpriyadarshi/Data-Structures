//
// Created by Vishisht Priyadarshi on 25-09-2019.
//

#include <iostream>
#include <cmath>


using namespace std;

void swap(int* a, int* b)                     // Swapping
{
    int t = *a;
    *a = *b;
    *b = t;
}

int Partition(int *a, int p, int r)           // Partitioning
{
    int i = p-1;

    for(int j = p; j < r ; j++)
    {
        if(a[j] <= a[r])
        {
            i = i + 1;
            swap(&a[i], &a[j]);
            
        }

    }

    swap(&a[i+1], &a[r]);

    return i+1;
}

void QuickSort(int *a , int p , int r)
{
    if(p < r)
    {
        int q = Partition(a,p,r);
        QuickSort(a, p, q-1);
        QuickSort(a, q+1, r);
    }
}

void print(int *a, int size)
{

    for(int i = 0; i < size; i++)
        cout << a[i] << " ";
}

int main()
{
    cout << "Enter length :\n";
    int size;
    cin >> size;

    int *a = new int[size];

    for(int i = 0; i < size; i++)
        cin >> a[i];

    QuickSort(a,0,size-1);

    print(a,size);

    return 0;
}
