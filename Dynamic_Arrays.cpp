#include <iostream>
using namespace std;


// ===========================================
//             Helper Function
// ===========================================


int* addArray(int n,int *A,int* ct,int* size)
{
    if(*ct < *size)                       // For Insertions without the need of doing Resizing Array
    {
        A[*ct] = n;                       // Insertion in O(1) time
        (*ct)++;
        
        return A;
    }
    else                                  // For Insertions with resizing the Array
    {
        int *A2 = new int[(*ct)*2];       // Dynamic Memory allocation to double the size of Array
        (*size) = (*ct)*2;

        for(int i = 0; i<*ct; i++)
            A2[i] = A[i];                 // Copying the elements of the old array into resized array

        A2[*ct] = n;                      // Insertion in O(n) time
        (*ct)++;

        return A2;
    }
}



// ========================================================
//                    Main Function 
// ========================================================


int main()
{
    int l = 0;

    cout << "Enter the size of array:";
    cin >> l;

    int *A = new int[1];
    cout << "Enter elements:";

    int size = 1;                          // SIZE of the Array
    int ct = 0;                            // Position of last inserted element

    while(l--)
    {
        int a;
        cin >> a;
        A = addArray(a,A,&ct,&size);       // Adding elements to Array
    }

    for(int i = 0;i<ct;i++)
        cout << A[i] << " ";

    cout << "\n" << size;
    
    return 0;
}
