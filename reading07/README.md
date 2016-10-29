Reading 07
==========

1. A hash function generates an index from a key. It is used to map data of any size to a fixed size.

2. A collision is when multiple data values are mapped, using the hash function, to the same index. Separate chaining handles collisions by having a list at each index of the hash table. These lists are called buckets and can store all data mapped to that index.

3. A good hash function is quick to compute and provides uniform mapping of elements regardless of values. This doesn't mean absolutely perfect removal of collisions, but fairly good minimization.

4. Big O for hash table using separate chaining

	1. Search: Average = O(1), Worst = O(n)
	2. Insert: Average = O(1), Worst = O(n)
	3. Remove: Average = O(1), Worst = O(n)

The reason the average and worst case time complexities are different for all three of these actions because if the hash function is bad, then one bin could contains all of the data elements. Then this bin acts as a linked list with its efficiency for search. If everything causes a collision, then insertion/deltion become linear as well. 
