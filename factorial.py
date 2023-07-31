def factorial(n):
    res = 1
    for k in range(1, n+1):
        res *= k
    return res

print(factorial(3))
print(factorial(4))
print(factorial(9))
