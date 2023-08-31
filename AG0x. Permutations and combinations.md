## Python: `itertools`를 이용한 방법

파이썬에 내장된 itertools패키지의 combinations모듈과 permutations모듈을 통해 손쉽게 순열과 조합을 구할 수 있다. 이때, 만들어진 순열과 조합은 튜플의 형태로 리스트에 담겨서 반환된다.

조합

```python
from itertools import combinations
arr = [0, 1, 2, 3, 4, 5]
print(list(combinations(arr, 3)))
```

순열

```python
from itertools import permutations
arr = [0, 1, 2, 3, 4, 5]
print(list(permutations(arr, 3)))
```

## Combination using recursion

The basic idea is as follows:

```
combination([0,1,2,3], 2) 
= ([0],combination([1,2,3], 1)) 
+ ([1],combination([2,3], 1)) 
+ ([2],combination([3], 1))

combination([3], 1) 
= ([3],combination([], 0))

combination([2,3], 1) 
= ([2],combination([3], 0))
= ([3],combination([], 0))

combination([1,2,3], 1)
= ([1],combination([2,3], 0))
+ ([2],combination([3], 0))
+ ([3],combination([], 0))
```

```python
def getCombi(arr, n):
  res = []
  if n == 0:
    return [[]]
  for i in range(len(arr)-n+1):
    for combi in getCombi(arr[i+1:], n-1):
      res.append([arr[i]]+combi)
  return res

arr = [0, 1, 2, 3]
print(getCombi(arr, 2))
```
The output is:
```
[[0, 1], [0, 2], [0, 3], [1, 2], [1, 3], [2, 3]]
```

## Permutation using recursion

The basic idea is as follows:
```
permutation([0,1,2,3], 2) 
= ([0],permutation([1,2,3], 1)) 
+ ([1],permutation([0,2,3], 1)) 
+ ([2],permutation([0,1,3], 1))
+ ([3],permutation([0,1,2], 1))
```

```python
def getPerm(arr, n):
  res = []
  if n==0:
    return [[]]
  for i in range(len(arr)):
    for rest in getPerm(arr[:i]+arr[i+1:],n-1):
      res.append([arr[i]]+rest)
  return res

arr = [0, 1, 2, 3]
print(getPerm(arr, 2))
```
The output is:
```
[[0, 1], [0, 2], [0, 3], [1, 0], [1, 2], [1, 3], [2, 0], [2, 1], [2, 3], [3, 0], [3, 1], [3, 2]]
```