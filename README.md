# MA-251-Data-Structures

### 1. Dynamic Arrays
The dynamic allocation of arrays is done through *new* keyword.
My implementation of the Dynamic Arrays is such that the size of array doubles every time its limit is reached. The insertion operation takes **O(1) time** unless the array is resized, and during resizing operation it takes **O(n)** time where n = size of the array at a particular instant. But **Amortied Insertion Time** is **O(1)**.

Some References:

(i)  http://www.fredosaurus.com/notes-cpp/newdelete/50dynamalloc.html

(ii) http://www.cplusplus.com/doc/tutorial/dynamic/
