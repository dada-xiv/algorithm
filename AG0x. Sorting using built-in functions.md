# Sorting using built-in functions

## Quick sort in C or C++: using `qsort()`

In C, `stdlib.h` provides `qsort()` for quick sort. In C++, `<cstdlib>` provides `qsort()`. Following is the declaration for `qsort()` function.
```c
#include <stdlib.h>
void qsort(void *base, size_t nitems, size_t size, int (*compare)(const void *, const void*))
```
The parameters are:
- `base` : the pointer to the first element of the array to be sorted.
- `nitems` : the number of elements in the array pointed by base.
- `size` : the size in bytes of each element in the array.
- `compare` : the function that compares two elements.

The `qsort()` function is used to sort an array or memory block. It takes the address of the array, the number of elements, the size of each element, and a comparison function as arguments. The data types of the elements to be sorted may vary, and several comparison methods can be used. Therefore, we implement a comparison function and pass its memory address (function pointer) as an argument to `qsort()`.

For example, let's implement the comparison function for ascending order. The comparison function should behave as follows:
- Return a negative value if `a` is less than `b`.
- Return a positive value if `a` is greater than `b`.
- Return `0` if `a` is equal to `b`.

When defining the comparison function, it must have an `int` return value and two `const void` pointer parameters. Since we cannot compare values directly with `const void` pointers, we convert the `const void` pointer to the appropriate data type (e.g., `int` pointer) and then dereference it to obtain the value for comparison. Here's an implementation of a comparison function for ascending order:
```c
int compare(const void *a, const void *b) {
    int num1 = *(int *)a; 
    int num2 = *(int *)b;

    if (num1 < num2) // If 'a' is smaller than 'b', return -1
        return -1;
    if (num1 > num2) // If 'a' is greater than 'b', return 1
        return 1;
    return 0; // 'a' and 'b' are equal, return 0
}
```

Alternatively, we can use a simpler implementation that directly returns the subtraction of the two parameters:

```c
int compare(const void *a, const void *b) {
    return *(int *)a - *(int *)b; // For ascending order
}
```

In this implementation, the return value does not need to be specifically -1, 1, or 0. It only needs to be 0 when the values are equal and return negative and positive numbers when the values are less than or greater than each other.

Here is a practical use of this `compare()` function to sort an array of integers in ascending order in C:
```c
#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int main() {
    int arr[] = {9, 17, 13, 9, 11, 12, 10};
    int len = sizeof(arr) / sizeof(arr[0]);

    qsort(arr, len, sizeof(int), compare);

    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
```
In C++, the same code is as follows:
```cpp
#include <iostream>
#include <cstdlib>

int compare(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int main() {
    int arr[] = {9, 17, 13, 9, 11, 12, 10};
    int len = sizeof(arr) / sizeof(arr[0]);

    std::qsort(arr, len, sizeof(int), compare);

    for (int i = 0; i < len; i++) {
        std::cout << arr[i] << " ";
    }
    return 0;
}
```
Output:
```
9 9 10 11 12 13 17 
```

## In C++: using `sort()`

In C++, `sort()` is a standard algorithm provided by the C++ Standard Library's `<algorithm>` header. It is used to sort elements in a container, such as an array or a `std::vector`, in ascending order by default. We can also specify a custom comparison function to sort elements in a different order.

Here's the prototpyes of the `sort()` function:
```cpp
template <class RandomAccessIterator>
void sort(RandomAccessIterator first, RandomAccessIterator last);

template <class RandomAccessIterator, class Compare>
void sort(RandomAccessIterator first, RandomAccessIterator last, Compare comp);
```

- `first` and `last` are iterators that define the range of elements to be sorted. The elements between `first` (inclusive) and `last` (exclusive) will be sorted.
- `comp` is an optional parameter that allows us to specify a custom comparison function for sorting. If not provided, `sort()` will use the default comparison function (operator `<`) to perform the sorting in ascending order.

Usage example:
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers = {5, 2, 8, 1, 3, 6};

    // Sort the vector in ascending order (default)
    std::sort(numbers.begin(), numbers.end());

    for (const auto& num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

Output:
```
1 2 3 5 6 8
```

If we want to sort elements in descending order or use a custom sorting criteria, we can provide a custom comparison function as the third argument to `sort()`:

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

bool compare(int a, int b) {
    // Sort in descending order
    return a > b;
}

int main() {
    std::vector<int> numbers = {5, 2, 8, 1, 3, 6};

    // Sort the vector in descending order using compare
    std::sort(numbers.begin(), numbers.end(), compare);

    for (const auto& num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

Output:

```
8 6 5 3 2 1
```

In this example, we use the `customComparator` function to sort the `numbers` vector in descending order. The `sort()` function uses this custom comparison function to determine the order of elements during the sorting process.

## Python: Using `.sort()` for list

In Python, the `.sort()` method is a built-in list method used to sort the elements of a list in ascending order. It modifies the original list in place, meaning that the list is sorted directly without creating a new sorted list.

In CPython (the standard implementation of Python), the `.sort()` method for lists uses a hybrid sorting algorithm that combines elements of **Timsort** and **Insertion Sort**. Timsort is a highly efficient sorting algorithm that is based on merge sort and insertion sort. It was designed to perform well on many kinds of real-world data. The algorithm used in `.sort()` switches between Timsort and Insertion Sort based on the size of the list and the number of elements being sorted. For smaller lists, it falls back to Insertion Sort, which has lower overhead for small collections. For larger lists, it switches to Timsort for its overall superior performance. The complexity of Timsort is $O(n \ln n)$ in the worst case and average case, making it highly efficient for most scenarios.

Here's an example of how to use the `.sort()` method:

```python
arr = [9, 17, 13, 9, 11, 12, 10]
arr.sort()

print(arr)
```

The output will be:

```
[9, 9, 10, 11, 12, 13, 17]
```

If we want to sort the list in descending order, we can use the `reverse` argument of the `.sort()` method:

```python
arr.sort(reverse=True)
```

If `arr` is a 2D array and we want to sort it based on a specific element, we can use the `key` argument with a `lambda` function:
```python
arr.sort(key=lambda x: x[1])
```
Here, `key=lambda x: x[1]` implies sorting based on the second element from each entry.