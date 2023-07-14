# Sorting

## Implementing or using sorting algorithms in practice

Examples of $O(N^2)$ sorting algorithms include **bubble sort**, **selection sort**, and **insertion sort**.

**Merge sort** and **heap sort** are examples of sorts with a complexity of $O(N\log N)$ or less. Alternatively, **radix sort** or **counting sort** can also achieve this complexity.

**Quicksort** has a worst-case time complexity of $O(N^2)$. Don't be fooled by the "quick" in the name. While the average time complexity is $O(N\log N)$, the ordinary implementation of quicksort can easily result in a worst-case time complexity of $O(N^2)$. In simple terms, quicksort struggles with already sorted or reverse-sorted inputs. There are ways to mitigate this issue, such as choosing the median of the medians as a pivot, using a different sorting algorithm when the recursion depth increases, or randomly shuffling the input beforehand. However, unless implemented very carefully, the efficiency of quicksort can still be very poor. Therefore, it is generally recommended not to use quicksort for algorithmic problems and to implement it only for practice purposes.

If you want to implement your own sorting algorithm without using built-in functions, merge sort is the easiest to understand and debug. When performing merge sort, it is important not to repeatedly allocate and deallocate the entire size of the array or subarrays each time a merge operation is performed. Allocating memory of size $N$ takes $O(N)$ time, and since merge is called $O(N)$ times, the total time complexity becomes $O(N^2)$. To address this issue, you can preallocate a larger array for copying in advance and only allocate memory equal to the size of the section covered by the merge operation (right - left + 1).
