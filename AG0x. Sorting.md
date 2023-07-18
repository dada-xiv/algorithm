# Sorting

## Selection sort

Selection sort is a brute force method and one of the simplest sorting algorithms. It follows the following procedure: Initially, we find the smallest element in the array and exchange it with the element in the first position. Then, we find the second smallest element in the array and exchange it with the element in the second position. This process continues until it is completed.

```c
void selectionSort(int a[], int n){
    int min;
    for(int i=0;i<n-1;i++){
        min = a[i];
        for(int j=i+1;j<n;j++){
            if(a[j] < min){
                a[i] = a[j];
                a[j] = min;
                min = a[i]; // The new a[i] is the smallest
            }
        }
    }
}
```

Selection sort is easy to implement, and there is little that can go wrong with it. However, this method requires $O(N^2)$ comparisons, so it is recommended to be used only on small files.

There is an important exception to this rule. When sorting files with large records and small keys, the cost of exchanging records determines the running time. In such cases, selection sort requires $O(N)$ time since the number of exchanges is at most $N$.

## Bubble sort

## Merge sort

When implemented in a general way, merge sort belongs to the stable sorting algorithms and is one of the *divide and conquer* algorithms. The divide and conquer method is a strategy in which a problem is divided into two smaller subproblems, each of which is solved independently, and the results are then combined to solve the original problem. Divide and conquer methods are typically implemented using recursive calls. The specific process of merge sort is as follows:

1. If the length of the list is 0 or 1, it is already considered sorted. Otherwise, the unsorted list is divided in half, creating two sublists of similar size.
2. Each sublist is recursively sorted using merge sort.
3. The two sorted sublists are merged back into one sorted list.

Merge sort typically requires an additional array. During the sorting process of each subarray, merge sort is called recursively and applied.

Suppose we are given an array `a[] = {23, 8, 15, 19, 11, 27, 10, 12, 21}`, and we want to sort it in ascending order. We send the array to the function `mergeSort(int *a, int left, int right)`. If `left < right`, indicating that the length of the given array is greater than 1, we divide it into two parts. The initial left index is `left = 0`, and the right index is `right = 8`, so the first dividing point is `mid = (left + right) / 2 = 4`. Then, we input each subarray into the function recursively as `mergeSort({23, 8, 15, 19, 11}, 0, 4)` and `mergeSort({27, 10, 12, 21}, 5, 8)` respectively. The function `mergeSort(int *a, int left, int right)` is as follows:

```c
void mergeSort(int *a, int left, int right){
    int mid;
    if(left < right){
        mid = (left + right) / 2;

        mergeSort(a, left, mid);
        mergeSort(a, mid + 1, right);

        // After two subarrays are sorted, we merge them together
        merge(a, left, mid, right);
    }
}
```

The function `merge(int *a, int left, int mid, int right)` actually merges the two sorted subarrays together. We need the `mid` variable because we require the precise middle index position that divides the left and right subarrays. We generate the sorted array by comparing each pivot index point for both subarrays, `pivotL` and `pivotR`, and copy the smaller values first to the sorted array to create the final ascending ordered array. We move each pivot point backward one by one as it is copied to the sorted array. Additionally, we increment `k`, which indicates the index of the sorted array during the merging process:

```c
#define SIZE 9
int sorted[SIZE]; // Global array for sorted result

void merge(int *a, int left, int mid, int right){
    int pivotL = left;
    int pivotR = mid + 1;
    int k = left;

    while(pivotL <= mid && pivotR <= right){
        if(a[pivotL] <= a[pivotR]){
            sorted[k] = a[pivotL];
            pivotL++;
            k++;
        }else{
            sorted[k] = a[pivotR];
            pivotR++;
            k++;
        }
    }

    // Copy the remaining elements
    if(pivotL <= mid){
        for(int i = pivotL; i <= mid; i++){
            sorted[k] = a[i];
            k++;
        }
    }else if(pivotR <= right){
        for(int i = pivotR; i <= right; i++){
            sorted[k] = a[i];
            k++;
        }
    }

    // Copy the sorted result into the array
    for(int i = left; i <= right; i++){
        a[i] = sorted[i];
    }
}
```

After we sort all the elements by pivots, one of the pivot points `pivotL` or `pivotR` may not have been completely used, so we check if `pivotL <= mid` or `pivotR <= right`. If true, we copy the remaining elements to the sorted array to complete the merge sort process.

The entire code would be:
```c
#include <stdio.h>
#define SIZE 9
int sorted[SIZE]; // Global array for sorted result

void merge(int a[], int left, int mid, int right){
    int pivotL = left;
    int pivotR = mid + 1;
    int k = left;

    while(pivotL<=mid && pivotR<=right){
        if(a[pivotL] <= a[pivotR]){
            sorted[k++] = a[pivotL++];
        }else{
            sorted[k++] = a[pivotR++];
        }
    }

    // Copy the remaining elements
    if(pivotL<=mid){
        for(int i=pivotL;i<=mid;i++){
            sorted[k++] = a[i];
        }
    }else if(pivotR<=right){
        for(int i=pivotR;i<=right;i++){
            sorted[k++] = a[i];
        }
    }

    // Copy the sorted result into the array
    for(int i=left;i<=right;i++){
        a[i] = sorted[i];
    }
}

void mergeSort(int a[], int left, int right){
    int mid;

    if(left < right){
        mid = (left + right) / 2;
        mergeSort(a, left, mid);
        mergeSort(a, mid+1, right);
        merge(a, left, mid, right);        
    }
}

int main(){
    int N = SIZE;
    int a[] = {23, 8, 15, 19, 11, 27, 10, 12, 21};

    mergeSort(a, 0, N-1);

    for(int i;i<N;i++){
        printf("%d ", a[i]);
    }

    return 0;
}
```
The output will be:
```
8 10 11 12 15 19 21 23 27 
```

An advantageous aspect of merge sort is that it is not affected by data distribution. In other words, regardless of the input data, the resulting sorting time is always $O(n \log n)$. When implementing merge sort using an array, an auxiliary array is required. Consequently, if the record size is large, there will be many data movements, resulting in significant time waste. However, if merge sort is implemented using a linked list, only the link indexes are changed, and the data movements become significantly smaller, almost negligible. Additionally, it can be implemented as an in-place sorting algorithm. Therefore, when sorting a large amount of data, merge sort is efficient.

### Time complexity of merge sort

Suppose the data size is $n = 2^k$. In the division stage, comparison and movement operations are not executed. At the final recursive call, the total number of subarrays of size $1$ is $n$. Since the total size is $n = 2^k$, the depth of the recursive calls (number of merging stages) is $k = \log n$.

When merging two arrays of size $1$, there are $n/2$ pairs of subarrays, and each pair consists of $2$ elements. Hence, we perform $(n/2) \times 2 = n$ comparisons. For the next bottom stage, there are $n/2^2$ pairs of subarrays, and each pair consists of $2^2$ elements, so we need to perform $(n/2^2) \times 2^2 = n$ comparisons. Similarly, for the $k$-th merging stage, there are $n/2^k$ pairs of subarrays, and each pair consists of $2^k$ elements, so we need to perform $(n/2^k) \times 2^k = n$ comparisons. Thus, on each merge stage, $n$ elements are merged. Therefore, for $n$ elements, there will be $n \log 2$ division and merge stages in total. Regardless of the arrangement, the time complexity of merge sort is $O(n \log n)$.


## Counting sort

The counting sort algorithm is a sorting algorithms which do not require comparisons between values. These types of sorts are known as *non-comparison based* sorts. Instead, the counting sort algorithm sorts the elements of an array by counting the number of *occurrences* of each unique element in the array. The count is stored in an auxiliary array and the sorting is done by mapping the count as an index of the auxiliary array.

Suppose that the given array is `a[] = {2, 2, 3, 5, 1, 3}`. The maximum value of `a[]` is `max = 5`. We initialize an auxiliary array `crr[]` of length `max + 1` with all elements `0`. 

```
         0  1  2  3  4  5
crr[] = {0, 0, 0, 0, 0, 0}
```

This array will be used for storing the counts of the elements in the given array `a[]`. Then we store the count of each element at their respective index in the `crr[]` array.

```
         0  1  2  3  4  5
crr[] = {0, 1, 2, 2, 0, 1}
```

Of course, the total sum of the elements of `crr[]` should be the length of `a[]`. Next, we store cumulative sum of the elements of the count array. This cumulative summed array will be used to place the elements into the correct index of the sorted array.

```
         0  1  2  3  4  5
crr[] = {0, 1, 3, 5, 5, 6}
```

Now we does the actual sorting process. We find the index of each element of the original array in the counted array. This gives the cumulative count. We place the elements at the index calculated as shown below:


```
       v
a[] = {2, 2, 3, 5, 1, 3}

               v
         0  1  2  3  4  5
crr[] = {0, 1, 3, 5, 5, 6}  

The position in the array : 3-1 = 2

       0  1  2  3  4  5 
a[] = {_, _, 2, _, _, _}
```

When the element `2` is used, the cummulative number is decreased by 1 for the `2` element in `crr[]`, so that we have `crr[] = {0, 1, 2, 5, 5, 6}` for the next round. Hence even if we have multiple number of elements `2` in the original array, we can sorting them correctly.

```
          v
a[] = {2, 2, 3, 5, 1, 3}

               v
         0  1  2  3  4  5
crr[] = {0, 1, 2, 5, 5, 6}

The position in the array : 2-1 = 1

       0  1  2  3  4  5 
a[] = {_, 2, 2, _, _, _}
```

After this, we have `crr[] = {0, 1, 1, 5, 5, 6}` for the next round. 

```
             v
a[] = {2, 2, 3, 5, 1, 3}

                  v
         0  1  2  3  4  5
crr[] = {0, 1, 1, 5, 5, 6}

The position in the array : 5-1 = 4

       0  1  2  3  4  5 
a[] = {_, 2, 2, _, 3, _}
```
This procedure will be done until we place each element of `a[]`.


The entire code would be:
```c
#include <stdio.h>

void countingSort(int a[], int n) {
    // Creates a list of size max number in the array
    int max = a[0];
    for(int i=1;i<n;i++){
        if(a[i]>max) max = a[i];
    }

    int crr[max + 1];

    // Initialize count array with all zeros
    for(int i=0;i<=max;i++){
        crr[i] = 0;
    }

    // Store the count of each element
    for(int i=0;i<n;i++){
        crr[a[i]]++;
    }

    // Store the cumulative count of each array
    for(int i=1;i<=max;i++){
        crr[i] += crr[i-1];
    }

    // Sorting phase: Find the index of each element of the original array in count array, and place the elements in output array
    int result[n];
    for(int i=0;i<n;i++) {
        result[crr[a[i]]-1] = a[i];
        crr[a[i]]--;
    }

    // Copy the sorted elements into original array
    for(int i=0;i<n;i++){
        a[i] = result[i];
    }
}

int main() {
    int n;
    int c[] = {10, 8, 2, 3, 1, 2, 8, 4, 12, 3, 5, 11, 7, 5};

    n = sizeof(c)/sizeof(c[0]);
    countingSort(c, n);
    for (int i=0;i<n;i++) printf("%d ", c[i]);
    printf("\n");

    return 0;
}
```
The output will be:
```
1 2 2 3 3 4 5 5 7 8 8 10 11 12 
```

Note that if the limit of the maximum number is given, we can simplify further:
```c
#include <stdio.h>

#define SIZE 10000 // The limit of maximum number

void countingSort_simple(int a[], int n){
    int crr[SIZE+1] = {0};

    for(int i=0;i<n;i++){
        crr[a[i]] += 1;
    }

    int result[n];
    int idx = 0;
    for(int i=1;i<=SIZE;i++){
        if(crr[i]==0) continue;
        for(int j=0;j<crr[i];j++){
            result[idx] = i;
            idx++;
        }
    }

    for(int i=0;i<n;i++){
        a[i] = result[i];
    }
}

int main() {    
    int c[] = {10, 8, 2, 3, 1, 2, 8, 4, 12, 3, 5, 11, 7, 5};

    int n = sizeof(c)/sizeof(c[0]);
    countingSort_simple(c, n);
    for (int i=0;i<n;i++) printf("%d ", c[i]);
    printf("\n");

    return 0;
}
```

### Time complexity of countring sort

There are mainly four main loops:

| for-loop | time of counting |
|----------|------------------|
| 1st      | $O(\text{max})$  |
| 2nd      | $O(\text{size})$ |
| 3rd      | $O(\text{max})$  |
| 4th      | $O(\text{size})$ |

Hence, the overall complexity is $O(\text{max})+O(\text{size})+O(\text{max})+O(\text{size}) = O(\text{max+size})$. That is, the time complexity is dependent on the maximum value of the given array, denoted as $k$, so the time complexity of counting sort is $O(n+k)$, where $n$ is the size of the given array.

## Implementing or using sorting algorithms in practice

Examples of $O(N^2)$ sorting algorithms include **bubble sort**, **selection sort**, and **insertion sort**.

**Merge sort** and **heap sort** are examples of sorts with a complexity of $O(N\log N)$ or less. Alternatively, **radix sort** or **counting sort** can also achieve this complexity.

**Quicksort** has a worst-case time complexity of $O(N^2)$. Don't be fooled by the "quick" in the name. While the average time complexity is $O(N\log N)$, the ordinary implementation of quicksort can easily result in a worst-case time complexity of $O(N^2)$. In simple terms, quicksort struggles with already sorted or reverse-sorted inputs. There are ways to mitigate this issue, such as choosing the median of the medians as a pivot, using a different sorting algorithm when the recursion depth increases, or randomly shuffling the input beforehand. However, unless implemented very carefully, the efficiency of quicksort can still be very poor. Therefore, it is generally recommended not to use quicksort for algorithmic problems and to implement it only for practice purposes.

If we want to implement our own sorting algorithm without using built-in functions, merge sort is the easiest to understand and debug. When performing merge sort, it is important not to repeatedly allocate and deallocate the entire size of the array or subarrays each time a merge operation is performed. Allocating memory of size $N$ takes $O(N)$ time, and since merge is called $O(N)$ times, the total time complexity becomes $O(N^2)$. To address this issue, we can preallocate a larger array for copying in advance and only allocate memory equal to the size of the section covered by the merge operation (right - left + 1).

## Comparison of time complexities

Following table shows the time complexities for some of the most commonly used sorting algorithms.

| Sorting algorithm | Average       | Best          | Worst         |
|-------------------|---------------|---------------|---------------|
| Selection sort    | $O(n^2)$      | $O(n^2)$      | $O(n^2)$      |
| Insertion sort    | $O(n^2)$      | $O(n)$        | $O(n^2)$      |
| Bubble sort       | $O(n^2)$      | $O(n)$        | $O(n^2)$      |
| Quick sort        | $O(n \ln n)$  | $O(n \ln n)$  | $O(n^2)$      |
| Bucket sort       | $O(n+k)$      | $O(n+k)$      | $O(n^2)$      |
| Heap sort         | $O(n \ln n)$  | $O(n \ln n)$  | $O(n \ln n)$  |
| Merge sort        | $O(n \ln n)$  | $O(n \ln n)$  | $O(n \ln n)$  |
| Radix sort        | $O(n\cdot k)$ | $O(n\cdot k)$ | $O(n\cdot k)$ |
| Counting sort     | $O(n+k)$      | $O(n+k)$      | $O(n+k)$      |
