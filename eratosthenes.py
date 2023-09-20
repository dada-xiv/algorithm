N = 1000000
primes = [True for _ in range(N+1)]
for i in range(2, int((N)**0.5)+1):
  if primes[i]:
    for k in range(i+i, N+1, i):
      primes[k] = False
