'''
Merge sort
'''
SIZE  = 9
# Global array for sorted result
sorted = [0]*SIZE

def merge(a, left, mid, right):
    pivotL = left
    pivotR = mid + 1
    k = left

    while pivotL<=mid and pivotR<=right:
        if a[pivotL] <= a[pivotR]:
            sorted[k] = a[pivotL]
            k += 1
            pivotL += 1
        else:
            sorted[k] = a[pivotR]
            k += 1
            pivotR += 1

    # Copy the remaining elements
    while pivotL <= mid:
        sorted[k] = a[pivotL]
        k += 1
        pivotL += 1

    while pivotR <= right:
        sorted[k] = a[pivotR]
        k += 1
        pivotR += 1

    # Copy the sorted result into the array
    for i in range(left, right+1):
        a[i] = sorted[i]

def mergeSort(a, left, right):
    if left < right:
        mid = (left + right) // 2
        mergeSort(a, left, mid)
        mergeSort(a, mid+1, right)
        merge(a, left, mid, right)

N = SIZE # len(a)
a = [23, 8, 15, 19, 11, 27, 10, 12, 21]
mergeSort(a, 0, N-1)

print(a)