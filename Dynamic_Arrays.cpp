#include <iostream>

using namespace std;


int* addArray(int n,int *A,int* ct,int* size)
{

    if(*ct < *size)                     // Insertion in O(1) time
    {
        A[*ct] = n;
        (*ct)++;
        return A;

    }

    else
    {
        int *A2 = new int[(*ct)*2];      // Insertion in O(n) time
        (*size) = (*ct)*2;

        for(int i = 0; i<*ct; i++)
            A2[i] = A[i];

        A2[*ct] = n;
        (*ct)++;

        return A2;

    }
}

int main()
{
    int l = 0;

    cout << "Enter the size of array:";
    cin >> l;

    int *A = new int[1];
    cout << "Enter elements:\n";

    int size = 1;     // SIZE of the Array
    int ct = 0;       // Position of last inserted element

    while(l--)
    {
        int a;
        cin >> a;
        A = addArray(a,A,&ct,&size);
    }

    for(int i = 0;i<ct;i++)
        cout << A[i] << " ";

    cout << "\n" << size;
    return 0;
}
