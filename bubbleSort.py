'''
Bubble sort
'''

def bubbleSort(a, n):
    for i in range(n-1):
        for j in range(n-i-1):
            if a[j] > a[j+1]:
                temp = a[j]
                a[j] = a[j+1]
                a[j+1] = temp

a = [5, 6, 4, 7, 3, 1, 8, 2, 9, 0]
n = len(a)
bubbleSort(a, n)
print(a)
