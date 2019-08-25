    //
// Created by Vishisht Priyadarshi on 25-08-2019.
//

#include <iostream>
#define  SIZE 3
using namespace std;

struct queue
{
    int *a = new int[SIZE];
    int head;
    int tail;

};

// ==================================
//     Queues Class Specification
// ==================================


class Queues
{
    queue temp;

public:
    Queues();                    // Constructor

    void Enqueue(int e);         // Adds an element to the Queue

    int Dequeue();               // Removes an element from the Queue

    int Front();                 // Returns the front element of the queue

    int Rear();                  // Returns the last element from the queue

    bool isEmpty();              // Checks if queue is empty or not

    bool isFull();               // Checks if Queue is full or not

    void printQ();

};

// =====================================
//          Helper Functions
// =====================================

Queues::Queues()
{
    temp.head = 0;
    temp.tail = 0;

}

void Queues::Enqueue(int e)
{
    if(!(isFull())){
        temp.tail = (temp.tail + 1)%SIZE;
        temp.a[temp.tail] = e;
    }
    else
        cout << "Queue is FULL!\n";

}

int Queues::Dequeue()
{
    temp.head = (temp.head + 1)%SIZE;
    int val = temp.a[temp.head];


    return val;
}

int Queues::Front()
{
    return temp.a[temp.head+1];
}

int Queues::Rear()
{
    return temp.a[temp.tail];
}

bool Queues::isEmpty()
{
    return (temp.head == temp.tail);
}

bool Queues::isFull()
{
    cout << "Head = " << temp.head << "\nTail = " << temp.tail << "\n";
    return ((temp.tail+1)%SIZE == temp.head);
}

void Queues::printQ()
{
    //cout << temp.head <<" " << temp.tail << "\n";
    for(int i = (temp.head)+1; i <= temp.tail; i++)
    {
        cout << temp.a[i] << " ";
    }
}
// ============================================
//            Main Function
// ============================================


int main()
{
    Queues Q;

    Q.Enqueue(1);
    Q.Enqueue(2);
    Q.Enqueue(3);
    // Q.Enqueue(4);
    // Q.Enqueue(5);
    // Q.Enqueue(6);
    // Q.Enqueue(7);

        
    Q.printQ();
    cout <<"\n" << Q.Front();

    return 0;
}
