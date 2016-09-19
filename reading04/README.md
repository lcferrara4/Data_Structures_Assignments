Reading 04
==========

1. Merge sort:

The divide stage is splitting the array near its midpoint. The first size is n/2 and the second size is n - n1.

The conquer stage uses recursion to sort the two subarrays. And then merges the two subarrays.

2. Quick sort:

In the partitioning stage of the algorithm, an arbitrary pivot will be chosen. Then all values will be moved based on whether they are <= to the pivot or > the pivot. It moves towards the ends of the array to help with issue of an unknown pivot and its index.

Obtaining a good running times requires the choice of a good pivot element. Ideally, the pivot element chosen is near the middle of the subarray. If the array is already sorted, the worst time behavior occurs because the first element is chosen as the pivot and is smaller than everything else.

 second size is n - n1.

The conquer stage uses recursion to sort the two subarrays. And then merges the two subarrays.

2. Quick sort:

In the partitioning stage of the algorithm, an arbitrary pivot will be chosen. Then all values will be moved based on whether they are <= to the pivot or > the pivot. It moves towards the ends of the array to help with issue of an unknown pivot and its index.

Obtaining a good running times requires the choice of a good pivot element. Ideally, the pivot element chosen is near the middle of the subarray. If the array is already sorted, the worst time behavior occurs because the first element is chosen as the pivot and is smaller than everything else.

 second size is n - n1.

The conquer stage uses recursion to sort the two subarrays. And then merges the two subarrays.

2. Quick sort:

In the partitioning stage of the algorithm, an arbitrary pivot will be chosen. Then all values will be moved based on whether they are <= to the pivot or > the pivot. It moves towards the ends of the array to help with issue of an unknown pivot and its index.

Obtaining a good running times requires the choice of a good pivot element. Ideally, the pivot element chosen is near the middle of the subarray. If the array is already sorted, the worst time behavior occurs because the first element is chosen as the pivot and is smaller than everything else.

 second size is n - n1.

The conquer stage uses recursion to sort the two subarrays. And then merges the two subarrays.

2. Quick sort:

In the partitioning stage of the algorithm, an arbitrary pivot will be chosen. Then all values will be moved based on whether they are <= to the pivot or > the pivot. It moves towards the ends of the array to help with issue of an unknown pivot and its index.

Obtaining a good running times requires the choice of a good pivot element. Ideally, the pivot element chosen is near the middle of the subarray. If the array is already sorted, the worst time behavior occurs because the first element is chosen as the pivot and is smaller than everything else.

3. Stable sorting algorithms always have the same output, because the follow the rule: if two items compare as equal, then their relative order will be preserved, so that if one came before the other in the input, it will also come before the other in the output.

This characteristic is useful when using multiple keys to sort.

Merge sort is a stable sorting algorithm, whereas quicksort is not. Merge sort generally takes from the left subarray if elements are equal keeping the order. Quick sort exchanges nonadjacent elements and is randomized based on the pivot chosen, so it does not follow a set rule to keep equal elements in order.

4. 
Merge sort:
Best case = O(nlogn)
Average case = O(nlogn)
Worst case = O(nlogn)

Quicksort:
Best case = O(nlogn)
Average case = O(nlogn)
Worst case = O(n^2)

Quicksort is used more often, because it requires less storage than merge sort generally. Also even though its worst case time is worse than merge sort, this only happens in the special case of a presorted array. This can also be avoided by choice of pivot, often best if picked randomly.
