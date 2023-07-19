'''
Merge sort, without global sorted[]
'''

def merge(a, left, mid, right):
    pivotL = left
    pivotR = mid + 1
    k = left
    sorted = [0]*(right-left+1)

    while pivotL<=mid and pivotR<=right:
        if a[pivotL] <= a[pivotR]:
            sorted[k-left] = a[pivotL]
            k += 1
            pivotL += 1
        else:
            sorted[k-left] = a[pivotR]
            k += 1
            pivotR += 1

    # Copy the remaining elements
    while pivotL <= mid:
        sorted[k-left] = a[pivotL]
        k += 1
        pivotL += 1

    while pivotR <= right:
        sorted[k-left] = a[pivotR]
        k += 1
        pivotR += 1

    # Copy the sorted result into the array
    for i in range(left, right+1):
        a[i] = sorted[i-left]

def mergeSort(a, left, right):
    if left < right:
        mid = (left + right) // 2
        mergeSort(a, left, mid)
        mergeSort(a, mid+1, right)
        merge(a, left, mid, right)

a = [23, 8, 15, 19, 11, 27, 10, 12, 21]
N = len(a)
mergeSort(a, 0, N-1)

print(a)