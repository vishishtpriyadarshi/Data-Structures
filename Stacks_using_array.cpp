#include <iostream>
using namespace std;

struct S1{
    int p;
    int *arr = new int[100];
};


// ====================================
//         Stacks Class Specification
// ====================================

class Stacks
{
    S1 stack1;

public:
    Stacks();               // Constructor

    int push(int a);        // Push element into the stack

    int pop();              // Pop element from the Stack

    int top();              // Returns index of element at the top of the stack

};


// ===================================
//           Helper Functions
// ===================================

Stacks::Stacks() {
    stack1.p = -1;           // Initialising index counter
}


int Stacks::push(int a)
{
    if(stack1.p < 100)
    {
        stack1.arr[stack1.p+1] = a;
        stack1.p++;
        return 1;             // Flag showing "Push" operation is successful
    }

    return -1;                // Flag showing "Push" operation is unsuccessful
}


int Stacks::pop()
{
    if(stack1.p >= 0)
    {
        return stack1.arr[stack1.p--];
    }

    else return -1;            // Flag showing "Pop" operation is unsuccessful
}


int Stacks::top(){
    if(stack1.p>=0)
        return stack1.p;       // Returns index of Topmost value

    return -1;                 // Flag showing "Top" operation is unsuccessful
}


// ====================================
//          Main Function
// ====================================


int main()
{
    Stacks s1;

    cout << s1.push(1) << endl;
    cout << s1.push(2) << endl;
    cout << s1.push(3) << endl;
    cout << s1.push(4) << endl;
    cout << s1.push(5) << endl;
    cout << s1.pop() << endl;
    cout << s1.top() << endl;

    cout << s1.pop() << endl;
    cout << s1.pop() << endl;
    cout << s1.pop() << endl;
    cout << s1.pop() << endl;
    cout << s1.top() << endl;
    cout << s1.top() << endl;
    cout << s1.pop() << endl;



    return 0;
}
