# MA-251-Data-Structures

### 1. Dynamic Arrays
The dynamic allocation of arrays is done through **new** keyword.
It returns a pointer to the beginning of the new block of memory allocated. Its syntax is: 

"type" pointer = new "type";  
pointer = new  "type"[number_of_elements];
  
  
My implementation of the Dynamic Arrays is such that the size of array doubles every time its limit is reached. The insertion operation takes **O(1) time** unless the array is resized, and during resizing operation it takes **O(n)** time where n = size of the array at a particular instant. But **Amortied Insertion Time** is **O(1)**.

### -> MultiDimensional Dynamic Arrays   
A dynamic 2D array is basically an array of pointers to arrays. We can initialize it using a loop, like this:   
```
int** a = new int*[rowCount];
for(int i = 0; i < rowCount; ++i)
    a[i] = new int[colCount];

```   
The above, for colCount= 5 and rowCount = 4, would produce the following:   
![Multidimensional Dynamic Array](https://i.stack.imgur.com/M75kn.png)   


Some References:

(i)   http://www.fredosaurus.com/notes-cpp/newdelete/50dynamalloc.html   
(ii)  http://www.cplusplus.com/doc/tutorial/dynamic/   
(iii) https://stackoverflow.com/questions/936687/how-do-i-declare-a-2d-array-in-c-using-new   
(iv)  https://www.tutorialcup.com/cplusplus/dynamic-memory.htm   
(v)   https://eli.thegreenplace.net/2015/memory-layout-of-multi-dimensional-arrays   


### 2. Stacks   
Stack is a linear data structure which follows a particular order in which the operations are performed. The order may be LIFO(Last In First Out) or FILO(First In Last Out).   
It is an **abstract data type**.      

![Stacks](http://underthepressure.net/wp-content/uploads/2018/05/stack_representation-300x207.jpg)   


Mainly the following three basic operations are performed in the stack:

(i) **Push**: Adds an item in the stack. If the stack is full, then it is said to be an Overflow condition.   
(ii) **Pop**: Removes an item from the stack. The items are popped in the reversed order in which they are pushed. If the stack is empty, then it is said to be an Underflow condition.   
(iii) **Top**: Returns top element of stack.

**TIME COMPLEXITY of Various Operations:**   
Time Complexities of operations on stack:

push(), pop(), top() all take **O(1)** time.  

This is because of random acess property of Arrays (if implemented using arrays), and also as no looping condition is present in its implementation.      

### 3. Queues   
A queue is a data structure where we add elements at the back and remove elements from the front. In that way a queue is like “waiting in line”.   
The first one to be added to the queue will be the first one to be removed from the queue. This is also called a **FIFO (First In First Out) data structure**.   

Mainly the following three basic operations are performed in the stack:

(i) **Enqueue**: Adds an item in the queue. If the queue is full, then it is said to be an Overflow condition.   
(ii) **Dequeue**: Removes an item from the back of Queue.   
(iii) **Front**: Returns beginning element of Queue.   
(iv) **Rear**: Returns last entered element of Queue.   

#### => Visualisation of Circular Queue:   
In our Implementation, the size of Queue is **MAX_SIZE - 1**.   

i) ![Queues]Img\Q1.png)    

* * *
## Project Author  

**Vishisht Priyadarshi**  

B.Tech Undergraduate (Mathematics and Computing)  
Indian Institute of Technology Guwahati  
India

[LinkedIn](https://www.linkedin.com/in/vishisht-priyadarshi-34068b179?fbclid=IwAR2gKntA7S027YRocf9gXuaoQS_g7tm8vTGjNJColC99v4UkZN4d9s6YhWw)
