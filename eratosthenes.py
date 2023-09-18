n = 20
sieve = [False]*(n+1)

for i in range(2, n+1):
  if sieve[i] == False:
    print(i, end=' ')
    for j in range(i, n+1, i):
      if sieve[j] == False:
        sieve[j] = True
