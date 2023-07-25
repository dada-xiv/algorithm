# Binary search

**Binary search** is a search algorithm that finds the position of a target value within a sorted array. Binary search compares the target value to the middle element of the array. If the target value matches the element, then its position is returned. If the target value are not equal to the middle element, then the half in which the target cannot lie is eliminated and the search continues on the remaining half, again taking the middle element to compare to the target value, and repeating this procedure until the target value is found. If the search ends with the remaining half being empty, then the target value is not in the given array.

Given an array $a$ of $n$ elements with values $a_0$, $a_1$, $\ldots$, $a_{n-1}$ sorted such that 
$a_0 \le a_1 \le a_2 \le \cdots \le a_{n-1}$ and the target value $t$, the following subroutine finds the index of $t$ in $a$, if it is existed in the array.

1. Set $L$ to $0$ and $R$ to $n-1$.
2. If $L > R$, the search terminates as unsuccessful.
3. Set $m$ (the position of the middle element) to the floor of $\frac{L+R}{2}$, which is the greatest integer less than or equal to $\frac{L+R}{2}$.
4. If $a_{m} < t$, set $L = m+1$ and go to step 2.
   If $a_{m} > t$, set $R = m-1$ and go to setp 2.
   If $a_{m} = t$, the search is done; return $m$.

```C
#include <stdio.h>

int binarySearch(int a[], int L, int R, int target){
    int m;
    while(L <= R){
        m = (L+R)/2;
        if(a[m] == target){
            return m;
        }else if(a[m] > target){
            R = m-1;
        }else{
            L = m+1;
        }
    }
    return -1;
}

int main() {
    int arr[] = {1, 3, 4, 5, 7, 9, 10, 11, 12, 13, 13, 13, 17, 19, 20};
    int len = sizeof(arr) / sizeof(arr[0]);

    printf("%d\n", binarySearch(arr, 0, len-1, 12));

    // If duplicate elements are present, it returns one of the indices.
    printf("%d\n", binarySearch(arr, 0, len-1, 13));

    printf("%d\n", binarySearch(arr, 0, len-1, 15));
    
    return 0;
}
```
The output:
```
8
11
-1
```

## Time complexity of binary search


In the algorithm, the array is repeatedly divided into two halves until the target element is found or the search space becomes empty (L > R). At each iteration, the search space is halved, hence the formula for the time complexity of binary search is 

$$T(n) = T(n/2) + c\,,$$

where $T(n)$ represents the time taken to search an array of size $n$. That is, each step of the loop has constant complexity except for the main part that calls the loop again, and halves the array. This is because in the remaining part, we only need to check whether `a[m]` is equal to `target`, whether `L` and `R` are equal and so on. Such remaining require basic operations that meet the conditions. Let $n=2^k$, then the entire time complexity for the worst case becomes 

$$
\begin{align*}
T(n) & = T(n/2) + c \\
& = T(n/2^2) + 2c \\
& = T(n/2^3) + 3c \\
& \cdots \\
& = T(n/2^k) + k c \\
& = T(1) + c \ln n \\
\end{align*}
$$

Therefore the time complexity of the algorithm is $O(\ln n)$, where $n$ is the number of elements in the input array. 
