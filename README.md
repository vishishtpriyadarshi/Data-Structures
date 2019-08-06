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
![alt text](https://i.stack.imgur.com/M75kn.png)   


Some References:

(i)   http://www.fredosaurus.com/notes-cpp/newdelete/50dynamalloc.html   
(ii)  http://www.cplusplus.com/doc/tutorial/dynamic/   
(iii) https://stackoverflow.com/questions/936687/how-do-i-declare-a-2d-array-in-c-using-new   
(iv)  https://www.tutorialcup.com/cplusplus/dynamic-memory.htm




* * *
## Project Author  

**Vishisht Priyadarshi**  

B.Tech Undergraduate (Mathematics and Computing)  
Indian Institute of Technology Guwahati  
India

[LinkedIn](https://www.linkedin.com/in/vishisht-priyadarshi-34068b179?fbclid=IwAR2gKntA7S027YRocf9gXuaoQS_g7tm8vTGjNJColC99v4UkZN4d9s6YhWw)
