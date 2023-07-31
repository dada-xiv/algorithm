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

### Examples
- [binarySearch.c](binarySearch.c)
- [binarySearch.cpp](binarySearch.cpp)
- [binarySearch.py](binarySearch.py)

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

## Search, insert, and delete in an sorted array

In a sorted array, a search operation can be performed for the possible position of the given element by using binary search, and then an insert operation is performed followed by shifting the elements. However, finding an element in a vector or list, erasing it, and shifting back elements one by one all have a time complexity of O(n). Consequently, the overall execution time becomes O(n^2), which could lead to a time limit error.

Instead, it is recommended to use a hash map or a hashed data structure like a Python dictionary. With a hash map, the average time complexity for insertion, deletion, and retrieval operations is O(1), making it much more efficient than using a vector or list in this scenario.

### Examples
- [insertDeleteSorted.py](insertDeleteSorted.py) - not a good implementation

## Using `bsearch()` in C

In C, `stdlib.h` provides `bsearch()` for binary search. Following is the declaration for `bsearch()` function.

```c
#include <stdlib.h>
void bsearch (const void *key, const void *base, size_t num, size_t width, int (*compare)(const void *key, const void *element))
```

The `bsearch()` function performs a binary search of an array of `num` elements, each of `width` bytes. The array must be sorted in ascending order by the function pointed to by `compare`. The `base` is a pointer to the base of the array to search, and `key` is the value being sought.

The `compare` argument is a pointer to a function we must supply that compares two items and returns a value specifying their relationship. The first item in the argument list of the `compare()` function is the pointer to the value of the item that is being searched for. The second item in the argument list of the `compare()` function is a pointer to the array element being compared with the key. The `compare()` function must compare the `key` value with the array element and then return one of the following values:

|Value         |Meaning                   |
|--------------|--------------------------|
|Less than 0   |`key` less than element   |
|0             |`key` identical to element|
|Greater than 0|`key` greater than element|

The `bsearch()` function returns a pointer to key in the array to which base points. If two keys are equal, the element that key will point to is unspecified. If the `bsearch()` function cannot find the key, it returns `NULL`.

The following code is converting the previous code into the version using `bsearch()`.
```C
#include <stdio.h>
#include <stdlib.h>

int compare(const void *key, const void *element){
    int nkey = *(int *)key;
    int nElement = *(int *)element;
    if(nkey > nElement) return 1;
    else if(nkey < nElement) return -1;
    else return 0;
}

int main() {
    int arr[] = {1, 3, 4, 5, 7, 9, 10, 11, 12, 13, 13, 13, 17, 19, 20};
    int len = sizeof(arr) / sizeof(arr[0]);
    int *p;
    int key;

    key = 12;
    p = (int *)bsearch(&key, arr, len, sizeof(int), compare);
    if (p != NULL) {
        printf("%d\n", (int)(p - arr));
    } else {
        printf("Key not found.\n");
    }

    // If duplicate elements are present, it returns one of the indices.
    key = 13;
    p = (int *)bsearch(&key, arr, len, sizeof(int), compare);
    if (p != NULL) {
        printf("%d\n", (int)(p - arr));
    } else {
        printf("Key not found.\n");
    }

    key = 15;
    p = (int *)bsearch(&key, arr, len, sizeof(int), compare);
    if (p != NULL) {
        printf("%d\n", (int)(p - arr));
    } else {
        printf("Key not found.\n");
    }
    
    return 0;
}
``` 
Output:
```
8
11
-1
```

## Using `binary_search()` in C++

`std::binary_search()` is a standard algorithm in C++ provided by the C++ Standard Library's `<algorithm>` header. It allows us to perform a binary search on a sorted range of elements. The function checks whether a given value exists in the sorted range and returns a boolean value indicating whether the value is present or not.

Here's the function prototype:

```cpp
template <class ForwardIterator, class T>
bool binary_search(ForwardIterator first, ForwardIterator last, const T& value);
```

- `first` and `last` are iterators defining the range of elements to search through. The range must be sorted in ascending order.
- `value` is the element that we want to search for in the range.

The function returns `true` if the `value` is found in the range and `false` otherwise.

Usage example:
```cpp
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    vector<int> vec = {1, 3, 4, 5, 7, 9, 10, 11, 12, 13, 13, 13, 17, 19, 20};
    int key;
    bool isFound;

    key = 12;
    isFound = binary_search(vec.begin(), vec.end(), key);
    cout << isFound << endl;

    key = 13;
    isFound = binary_search(vec.begin(), vec.end(), key);
    cout << isFound << endl;

    key = 15;
    isFound = binary_search(vec.begin(), vec.end(), key);
    cout << isFound << endl;

    return 0;
}
```
Output:
```
1
1
0
```


## Using `lower_bound()` in C++

If we want to find the index of the key element using `std::binary_search`, we can achieve it by using `std::lower_bound` instead. `lower_bound` is part of the C++ Standard Library's `<algorithm>` header, and uses a binary search algorithm to find the position where an element should be inserted into a sorted range while maintaining the sorted order. 

The prototype of the `std::lower_bound` function is as follows:

```cpp
template <class ForwardIterator, class T>
ForwardIterator lower_bound(ForwardIterator first, ForwardIterator last, const T& value);
```

- `first` and `last` are iterators defining the range of elements to search through. The range must be sorted in ascending order.
- `value` is the element that you want to find or determine its lower bound in the range.

The function returns an iterator pointing to the first element in the range that is not less than `value`. In other words, it returns an iterator to the lower bound of the `value` in the sorted range. If the `value` is found in the range, `lower_bound` returns an iterator pointing to the first occurrence of the `value`. 

If the `value` is not found, it returns an iterator pointing to the position where the `value` should be inserted in order to maintain the sorted order.

Here's how we can use `std::lower_bound` to find the index of the key element:

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    vector<int> vec = {1, 3, 4, 5, 7, 9, 10, 11, 12, 13, 13, 13, 17, 19, 20};
    int key;
    int index;

    key = 12;
    auto it = lower_bound(vec.begin(), vec.end(), key);
    index = distance(vec.begin(), it);
    if (it != vec.end() && *it == key) {
        cout << key << " found at index: " << index << endl;
    } else {
        cout << key << " not found in the vector. It should be inserted at " << index << endl;
    }

    key = 13;
    it = lower_bound(vec.begin(), vec.end(), key);
    index = distance(vec.begin(), it);
    if (it != vec.end() && *it == key) {
        cout << key << " found at index: " << index << endl;
    } else {
        cout << key << " not found in the vector. It should be inserted at " << index << endl;
    }

    key = 15;
    it = lower_bound(vec.begin(), vec.end(), key);
    index = distance(vec.begin(), it);
    if (it != vec.end() && *it == key) {
        cout << key << " found at index: " << index << endl;
    } else {
        cout << key << " not found in the vector. It should be inserted at index: " << index << endl;
    }

    return 0;
}
```

Output:

```
12 found at index: 8
13 found at index: 9
15 not found in the vector. It should be inserted at index: 12
```


