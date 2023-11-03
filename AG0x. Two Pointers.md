# Two Pointers Algorithm

Given a **sorted array**, having `N` integers, we find if there exists any partial sequential sum which equals to given `M`.

모든 경우의 수를 다 해보면 $O(N^2)$이 된다.

- 현재의 부분 배열의 처음과 끝을 가리키는 포인터(pivot 위치) 2개를 지정한다. 시작:`start`, 끝:`end`로 한다.
- 처음에는 `start=end=0`이고 항상 `start<=end`

`start<N`일 동안 다음을 반복한다:
1. 현재의 부분합이 `M`보다 크거나 or `end=N`이면 `start++`
2. 현재의 부분합이 `M`보다 작고 `end<N`이면 `end++`
3. 현재의 부분합이 `M`과 같으면 결과 count를 증가하고 1로 돌아간다.

# 예제

`N = 10`, `a = [1, 2, 3, 4, 2, 5, 3, 1, 1, 2]`이고 
`M = 5`인 경우.

(start = 0 / end = 0) a[0:0]
 .
[1, 2, 3, 4, 2, 5, 3, 1, 1, 2]
Sum = 0

(start = 0 / end = 1) a[0:1]
 ..
[1, 2, 3, 4, 2, 5, 3, 1, 1, 2]
Sum = a[0] = 1

(start = 0 / end = 2) a[0:2]
 .  .
[1, 2, 3, 4, 2, 5, 3, 1, 1, 2]
Sum = a[0]+a[1] = 3

(start = 0 / end = 3) a[0:3]
 .     .
[1, 2, 3, 4, 2, 5, 3, 1, 1, 2]
Sum = a[0]+a[1]+a[2] = 6 > M

(start = 1 / end = 3) a[1:3]
    .  .
[1, 2, 3, 4, 2, 5, 3, 1, 1, 2]  (!!) 다음번에 start++
Sum = a[1]+a[2] = 5

(start = 2 / end = 3) a[2:3]
       ..
[1, 2, 3, 4, 2, 5, 3, 1, 1, 2]
Sum = a[2] = 3

(start = 2 / end = 4) a[2:4]
       .  .
[1, 2, 3, 4, 2, 5, 3, 1, 1, 2]
Sum = a[2]+a[3] = 7 > M

(start = 3 / end = 4) a[3:4]
          ..
[1, 2, 3, 4, 2, 5, 3, 1, 1, 2]
Sum = a[3] = 4

(start = 3 / end = 5) a[3:5]
          .  .
[1, 2, 3, 4, 2, 5, 3, 1, 1, 2]
Sum = a[3]+a[4] = 6 > M

(start = 4 / end = 5) a[4:5]
             ..
[1, 2, 3, 4, 2, 5, 3, 1, 1, 2]
Sum = a[4] = 2

(start = 4 / end = 6) a[4:6]
             .  .
[1, 2, 3, 4, 2, 5, 3, 1, 1, 2]
Sum = a[4]+a[5] = 7 > M

(start = 5 / end = 6) a[5:6]
                ..
[1, 2, 3, 4, 2, 5, 3, 1, 1, 2] (!!) 다음번에 start++
Sum = a[5] = 5

(start = 6 / end = 6) a[6:6]
                   .
[1, 2, 3, 4, 2, 5, 3, 1, 1, 2]
Sum = 0

(start = 6 / end = 7) a[6:7]
                   ..
[1, 2, 3, 4, 2, 5, 3, 1, 1, 2]
Sum = a[6] = 3

(start = 6 / end = 8) a[6:8]
                   .  .
[1, 2, 3, 4, 2, 5, 3, 1, 1, 2]
Sum = a[6]+a[7] = 4

(start = 6 / end = 9) a[6:9]
                   .     .
[1, 2, 3, 4, 2, 5, 3, 1, 1, 2] (!!) 다음번에 start++
Sum = a[6]+a[7]+a[8] = 5

(start = 7 / end = 9) a[7:9]
                      .  .
[1, 2, 3, 4, 2, 5, 3, 1, 1, 2]
Sum = a[7]+a[8] = 2

(start = 7 / end = 10) a[7:10] end=N
                      .     .
[1, 2, 3, 4, 2, 5, 3, 1, 1, 2]
Sum = a[7]+a[8]+a[9] = 4

(start = 8 / end = 10) a[8:10] end=N
                         .  .
[1, 2, 3, 4, 2, 5, 3, 1, 1, 2]
Sum = a[8]+a[9] = 3

(start = 9 / end = 10) a[9:10] end=N
                            ..
[1, 2, 3, 4, 2, 5, 3, 1, 1, 2]
Sum = a[9] = 2

(start = 10 / end = 10) a[10:10] end=N
                            .
[1, 2, 3, 4, 2, 5, 3, 1, 1, 2]
Sum = 0

### Examples
- [twoPointers.py](twoPointers.py)
```python
a = [1, 2, 3, 4, 2, 5, 3, 1, 1, 2]
M = 5
lenA = len(a)
start, end = 0, 0
while start < lenA:
  sumP = sum(a[start:end])
  if sumP < M and end < lenA:
    end += 1
  elif sumP > M or end == lenA:
    start += 1
  elif sumP == M:
    print("found =", a[start:end])
    start += 1
```

# Time complexity

이 알고리즘은 매 루프마다 항상 두 포인터 중 하나는 1씩 증가하고 있고, 각 포인터가 N번 누적 증가해야 알고리즘이 끝난다. 따라서 각각 배열 끝에 다다르는데 O(N)이라서 합쳐도 O(N)이 된다.

# 관련 문제:

2003 : 수들의 합
1644 : 소수의 연속합
1806 : 부분합
2230 : 수 고르기
1484 : 다이어트
2038 : 골룽 수열
2531 : 회전 초밥
2096 : 내려가기
2293 : 동전1