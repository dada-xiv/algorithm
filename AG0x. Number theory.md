# Fibonacci 수

피보나치 수는 0과 1로 시작한다. 0번째 피보나치 수는 0이고, 1번째 피보나치 수는 1이다. 그 다음 2번째 부터는 바로 앞 두 피보나치 수의 합이 된다.

이를 식으로 써보면 
```
Fn = Fn-1 + Fn-2 (n ≥ 2)
```
가 된다.

n=17일때 까지 피보나치 수를 써보면 다음과 같다.

```
0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597
```

Fibonacci 수 재귀호출 의사 코드는 다음과 같다: 
```
fib(n) {
    if (n = 1 or n = 2)
    then return 1;
    else return (fib(n - 1) + fib(n - 2));
}
```

Fibonacci 수 동적 프로그래밍 의사 코드는 다음과 같다: 
```
fibonacci(n) {
    f[1] <- f[2] <- 1;
    for i <- 3 to n
        f[i] <- f[i - 1] + f[i - 2];
    return f[n];
}
```

## Pisano period

1960년, IBM의 직원 Donald Wall은 피보나치 수열을 m으로 나눈 나머지가 주기를 이룬다는 것을 증명했다. 피사노 주기(Pisano period)는 피보나치 수를 K로 나눈 나머지는 항상 주기를 갖게된다는 원리이다.

주기의 길이가 P 일 때, N번째 피보나치 수를 M으로 나눈 나머지는 N%P번째 피보나치 수를 M을 나눈 나머지와 같다.

M=10^k 일 때, k > 2 라면, 주기는 항상 15*10^{k-1}이다.

## Examples
- [fibonacci.c](fibonacci.c)
- [fibonacci.py](fibonacci.py)
- [fibonacci_recursive.py](fibonacci_recursive.py)
- [fibonacci_dp.py](fibonacci_dp.py)

# 소인수분해 알고리즘
n = 72
```
72 = 2*2*2*3*3
```
72 % 2 ==0이므로 소인수에 2를 담는다
72/2 = 36

36 % 2 ==0이므로 소인수에 2를 담는다
36/2 = 18

18 % 2 ==0이므로 소인수에 2를 담는다
18/2 = 9

9는 2로 나누어떨어지지 않는다

9 % 3 ==0이므로 소인수에 3을 담는다
9/3 = 3

3 % 3 ==0이므로 소인수에 3을 담는다
3/3 = 1

1 % 4 !=0
1 % 5 !=0
...
1 % 72 !=0

단, n=16일 때, 
1 x 16 = 16
2 x 8 = 16
4 x 4 = 16
8 x 2 = 16
16 x 1 = 16
에서 2 x 8 = 16 은 8 x 2 = 16 과 대칭이다. 즉, 가운데 약수를 기준으로 해서 각 등식이 대칭적인 형태를 보이기 때문에 우리는 특정한 자연수 N이 소수인지 확인하기 위해 바로 가운데 약수까지만 '나누어떨어지는지' 확인하면 된다.

```python
import math
n = int(input())
sqrtN = int(math.sqrt(n))
k = 2

while k <= sqrtN:
  if n % k == 0:
    print(k)
    n = n//k
  else:
    k += 1

if n > 1:
  print(n)
```