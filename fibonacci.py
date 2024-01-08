'''
피보나치 수는 0과 1로 시작한다. 0번째 피보나치 수는 0이고, 1번째 피보나치 수는 1이다. 그 다음 2번째 부터는 바로 앞 두 피보나치 수의 합이 된다. 이를 식으로 써보면 Fn = Fn-1 + Fn-2 (n ≥ 2)가 된다. n=17일때 까지 피보나치 수를 써보면 다음과 같다.

0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597

n = 10이면 피보나치 수는 55이다.
n = 40이면 피보나치 수는 102334155이다.
'''

def getFibonacci(n):
  a = 0
  b = 1

  if n == 0:
    return a
  elif n == 1:
    return b
  else:
    for i in range(2, n):
      c = a + b
      a = b
      b = c
    return a + b

print(getFibonacci(10))
print(getFibonacci(40))
