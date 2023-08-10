'''
피보나치 수는 0과 1로 시작한다. 0번째 피보나치 수는 0이고, 1번째 피보나치 수는 1이다. 그 다음 2번째 부터는 바로 앞 두 피보나치 수의 합이 된다. 이를 식으로 써보면 Fn = Fn-1 + Fn-2 (n ≥ 2)가 된다. n=17일때 까지 피보나치 수를 써보면 다음과 같다.

0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597

n = 10이면 피보나치 수는 55이다.
'''

def getFibonacci(n):
    if n == 0:
        return 0
    elif n == 1:
        return 1
    else:
        return getFibonacci(n - 1) + getFibonacci(n - 2)

print(getFibonacci(10))