//
// Created by Vishisht Priyadarshi on 08-09-2019.
//
#include <iostream>
#include <cmath>
#include <climits>

using namespace std;
#define MAX INT_MAX

void print(int *a, int size)
{
    for(int i = 0; i < size; i++)
        cout << a[i] << " ";
    cout << "\n\n";
}

void merge(int *a, int p, int q, int r)  // Merge subarray1 -> (p - q) & subarray2 -> (q + 1 - r)
 {
    int n1 = q - p + 1 ;                 // n1 = size of subarray1
    int n2 = r - q;                      // n2 = size of subarray2

    int *L = new int[n1+1];
    int *R = new int[n2+1];

    for(int i = 0; i < n1; i++)
        L[i] = a[p+i];                   // Copying from pth index of array a till qth index(included)
    L[n1] = MAX;                         // Adding sentinel value

    //print(L,n1+1);

    for(int i = 0; i < n2; i++)          // Copying from (q + 1) th index of array a till rth index(included)
        R[i] = a[q + 1 + i];
    R[n2] = MAX;                         // Adding sentinel value

    //print(R,n2+1);


    int j = 0,i = 0;                      // Indicator variables of subarray

    for(int k = p; k <= r; k++)           // Merging two subarrays
    {
        if(L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
    }
    //cout << "MERGED:\n";
    //print(a,r+1);
    //cout << "**************\n";
}

void mergeSort(int *a, int p, int r)    // Index r is included ,i.e., initially r = size - 1
{
    if(p<r)
    {
        int q = p + (r-p)/2;            // Avoids Overflow
        mergeSort(a,p,q);
        mergeSort(a,q+1,r);
        merge(a,p,q,r);

    }
}



int main()
{
    cout << "Enter size:\n";
    int size;
    cin >> size;

    cout << "Enter array:\n";
    int *a = new int[size];

    for(int i = 0; i < size; i++)
        cin >> a[i];

    mergeSort(a,0,size-1);
    print(a,size);
    return 0;
}
