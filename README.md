# Handwritten-Queue-Library-with-its-own-Iterator-and-Allocator-like-STL-Queue
1. This is a handwritten queue library with its own iterator and allocator that just like STL Queue in C++
2. You can use this library as same as using STL queue library
3. Although the number of APIs of handwritten library may less than STL queue a little bit, it's ok to learn and use in most of situations
4. In addition to accessible API, you can combine this queue with standart header "algorithm", for you can feed this handwritten container to the most    of standart algorithms in C++

You can see the following directories and files:
<img width="227" alt="image" src="https://user-images.githubusercontent.com/98395922/213155691-de2a40a8-c407-469e-b652-86725e7aff11.png">

The source file "queue.h" contains the primary source code of handwritten queue library.
The source file "Myallocator.h" contains the source code which is mainly used to allocate memory space for queue container.
The source file "Myiterator.h" contains the source code used for supporting the 'Iterator pattern', which greatly make it more convenient.
The source file "main.cpp" is mainly used for testing the completeness and accuracy of library.

This toy project can used for exploiting and learning STL queue library design fundamentals for novices
