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

def deleteElement(a, n, target):
    pos = binarySearch(a, 0, n-1, target)
    del a[pos]

def insertSorted(a, n, target):
    i = n-1
    a.append('')
    while i>=0 and a[i] > target:
        a[i+1] = a[i]
        i -= 1
    a[i+1] = target

# A sorted list
a = [1, 3, 4, 5, 7, 9, 10, 11, 12, 13, 13, 13, 17, 19, 20]

print(a) # Before insertion

n = len(a)
target = 14

insertSorted(a, n, target)

print(a) # After insertion

deleteElement(a, n, 12)

print(a)