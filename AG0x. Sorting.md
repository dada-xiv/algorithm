# Sorting

## Selection sort

Selection sort is a brute force method and one of the simplest sorting algorithms. It follows the following procedure: Initially, we find the smallest element in the array and exchange it with the element in the first position. Then, we find the second smallest element in the array and exchange it with the element in the second position. This process continues until it is completed.

```c
void selectionSort(int *a, int N){
    int min;
    for(int i=0;i<N-1;i++){
        min = a[i];
        for(int j=i+1;j<N;j++){
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

The entire code woule be:
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

## Implementing or using sorting algorithms in practice

Examples of $O(N^2)$ sorting algorithms include **bubble sort**, **selection sort**, and **insertion sort**.

**Merge sort** and **heap sort** are examples of sorts with a complexity of $O(N\log N)$ or less. Alternatively, **radix sort** or **counting sort** can also achieve this complexity.

**Quicksort** has a worst-case time complexity of $O(N^2)$. Don't be fooled by the "quick" in the name. While the average time complexity is $O(N\log N)$, the ordinary implementation of quicksort can easily result in a worst-case time complexity of $O(N^2)$. In simple terms, quicksort struggles with already sorted or reverse-sorted inputs. There are ways to mitigate this issue, such as choosing the median of the medians as a pivot, using a different sorting algorithm when the recursion depth increases, or randomly shuffling the input beforehand. However, unless implemented very carefully, the efficiency of quicksort can still be very poor. Therefore, it is generally recommended not to use quicksort for algorithmic problems and to implement it only for practice purposes.

If we want to implement our own sorting algorithm without using built-in functions, merge sort is the easiest to understand and debug. When performing merge sort, it is important not to repeatedly allocate and deallocate the entire size of the array or subarrays each time a merge operation is performed. Allocating memory of size $N$ takes $O(N)$ time, and since merge is called $O(N)$ times, the total time complexity becomes $O(N^2)$. To address this issue, we can preallocate a larger array for copying in advance and only allocate memory equal to the size of the section covered by the merge operation (right - left + 1).