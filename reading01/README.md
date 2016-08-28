Reading 01
==========

1. We will have different data structures that can be used for many different types of data. Using a language with templates allows us to create these data structures once but implement them for all these different data types. This provides reusability and easy changes.

2. The Rule of Three states that if you explicitly implement a destructor, a copy constructor, or a copy assignment operator, you should implement all three. 

In the stack source code given in the C++ Templates Tutorial, a destructor is implemented but not the copy constructor or the copy assignment operator. The problem here is that if the programmer thought the compiler's default implementation of these member functions was not suitable for the particular class then the others are probably not either.

In order to fix this, I would add public member functions for the copy constructor and copy assignment operator as such:
   
// Copy Constructor
Stack(const Stack& other):
      	size(other.size),
	top(other.top),
	stackPtr(new T[other.size]){
      	std::copy(stackPtr, stackPtr + size, other.stackPtr);
   }

// Copy Assignment Operator
Stack& operator=(const Stack& other) {
      	T* newdata = new T[other.size];
      	std::copy(other.stackPtr, other.stackPtr+other.size, newdata);
      	delete[] stackPtr;
      	stackPtr = newdata;
      	size = other.size;
	top = other.top;
      	return *this;
   }

3.
a. O(1)
b. O(n)
c. O(1)
A vector's size is how many elements it currently has and a vector's capacity is the maximum number of elements it can hold. There would need to be an assert that size < capacity before an insertion. The time to reallocate space for an insertion once size is at capacity is not factored into the above complexity.

4.
a. O(n)
b. O(1) 
c. O(1)
It doesn't effect the complexity. Both have the same big-O time complexities for these situations. However, a doubly linked list should be used in situations when you need to move both forward and backward through the list.
