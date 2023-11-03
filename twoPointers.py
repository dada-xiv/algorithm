a = [1, 2, 3, 4, 2, 5, 3, 1, 1, 2]
M = 5

lenA = len(a)

start, end = 0, 0
while start < lenA:
  # print(f"[{start}:{end}] ", end='')
  sumP = sum(a[start:end])
  if sumP < M and end < lenA:
    end += 1
  elif sumP > M or end == lenA:
    if sumP == M:
      print("found =", a[start:end])
    start += 1
  elif sumP == M:
    print("found =", a[start:end])
    start += 1
