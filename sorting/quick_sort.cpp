/*
QUICKSORT(A, p, r)
if p < r
    Partition the subarray around the pivot, which ends up in A[q] 
    q = PARTITION(A, p, r)
    QUICKSORT(A, p, q - 1) // recursively sort the low side
    QUICKSORT(A, q + 1, r) // recursively sort the high side 

The key to the algorithm is the PARTITION procedure

Although quicksort sorts in place according to the definition. The amount of memory it uses aside from the array being sorted is not constant.
Since each recursive call requires a constant amount of space on the runtime stack, outside of the array being sorted, 
quicksort requires space proportional to the maximum depth of the recursion. As we’ll see now, that could be as bad as O(n) in the worst case.

Worst case runtime of quick sort is O(n*n). It happens when the partitioning produces one subproblem with n-1 elements and one with 0 elements.
It occurs when input array is already sorted.
*/