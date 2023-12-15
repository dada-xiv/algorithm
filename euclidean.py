def getGCD(m, n):
  while n != 0:
    r = m % n
    m = n
    n = r
  return m

def gcd(m, n):
  while n:
    m, n = n, m % n
  return m

print(getGCD(40, 232))
print(gcd(40, 232))
