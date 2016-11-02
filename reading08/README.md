Reading 08
==========

1. In open addressing, collisions are handled by placing an item in a different open spot of the array if the index found by hash(key) is full. It requires that the array be initialized so that the program can test to see if an array position already contains a record.  Linear probing is the process of checking consecutive spots until a vacant spot is found in which to insert the data. One problem with linear probing is that it can result in clustering of data, which then can take make insert take a long time.

2. The load factor is a fraction, alpha, equal to (Number of occupied table locations)/(the size of the table's array). The higher the load factor, the worse the average time and space complexity is for a hash table.

3. Example:

Bucket		Value
0		68
1		14
2		2
3		3
4		72
5		13
6		56
7		7
8		78
9		79

4. Complexity for Hash Table with Open Addressing:

Search:

	* Average: O(1)
	* Worst: O(n)

Insert:

	* Average: O(1)
	* Worst: O(n)

Remove:

	* Average: O(1)
	* Worst: O(n)

There are different time complexities for average and worst case, because when using open addressing, there is the possbility of having to go through every element to find the open space or the correct element.
