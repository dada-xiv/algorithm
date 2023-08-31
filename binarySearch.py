'''
Binary search
'''

def binarySearch(a, L, R, target):
  while L <= R:
    m = (L + R) // 2
    if a[m] == target:
      return m
    elif a[m] > target:
      R = m - 1
    else:
      L = m + 1
  return -1


arr = [1, 3, 4, 5, 7, 9, 10, 11, 12, 13, 13, 13, 17, 19, 20]
len_arr = len(arr)

print(binarySearch(arr, 0, len_arr - 1, 12))
# If duplicate elements are present, it returns one of the indices.
print(binarySearch(arr, 0, len_arr - 1, 13))
print(binarySearch(arr, 0, len_arr - 1, 15))
