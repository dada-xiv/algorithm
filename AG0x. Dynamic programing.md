# Dynamic programming

## Problem
The task is to write a program that calculates the number of possible card arrangements given a sequence of numbers ranging from 1 to 34. Each card can be arranged in any order. For example, for the sequence 1253011, there are six possible arrangements:
```
[1][2][5][30][1][1]
[1][2][5][30][11]
[1][25][30][1][1]
[1][25][30][11]
[12][5][30][1][1]
[12][5][30][11]
```

### Input
The input consists of a single line containing a sequence of numbers, given in order. The sequence can have a maximum length of 40 characters.

### Output
The output should consist of a single line, which displays the number of possible card arrangements.

### Solution using recursive fuction

```python
def cntWays(s):
    lenS = len(s)
    if lenS==0:
        return 1

    count = 0
    for i in range(1, min(3, lenS+1)):
        current = s[:i]
        next = s[i:]
        if (current[0]!='0' and int(current)<=34):
            count += cntWays(next)

    return count

a = input()
print(cntWays(a))
```
This code extracts valid card combinations of up to two digits from the given number string, for example "1253011". In the first round, it considers combinations such as `[1]253011` and `[12]53011`. Then, in subsequent rounds, it further splits the combinations. For example, `[1]253011` is split into `[1][2]53011` and `[1][25]3011`, while `[12]53011` is split into `[12][5]3011` and `[12][53]011`. However, combination `[53]` violate the rules and is not counted. The process continues with the remaining numbers, recursively searching for valid combinations in each round.

In the worst case, the function `cntWays()` will make recursive calls for each possible prefix of the string. Since each recursive call reduces the length of the string, the maximum depth of the recursion will be the same as the length of the input string, say `n`. Within each recursive call, the function performs a loop from 1 to 2 (or 3 if `n` is less than 3). Therefore, the loop will have a maximum of 2 (or 3) iterations. Overall, the function will have a time complexity of $O(2^n)$ or $O(3^n)$. This is because, for each character in the string, there are 2 (or 3) possibilities for splitting it (taking substrings of length 1 or 2, or 1, 2, or 3). The recursive calls multiply the possibilities exponentially. The time complexity of the function is exponential, leading to potential computational expenses for larger values of `n` and resulting in a possible Time Limit Exceed (TLE) error. To optimize the time complexity, we could consider using dynamic programming to store intermediate results and avoid redundant calculations.

### Solution using dynamic programming

```python
def cntWays(s):
    n = len(s)
    dp = [0]*(n + 1)
    dp[0] = 1

    for i in range(1, n+1):
        for j in range(1, min(3, i+1)):
            sub = s[i-j:i]
            if sub[0]!='0' and int(sub)<=34:
                dp[i] += dp[i-j]
            #print(dp, f"s[{i-j}:{i}] = {sub}")

    return dp[n]

a = input()
print(cntWays(a))
```
If the input string was "1253011", then the output will be:
```
[1, 1, 0, 0, 0, 0, 0, 0] s[0:1] = 1
[1, 1, 1, 0, 0, 0, 0, 0] s[1:2] = 2
[1, 1, 2, 0, 0, 0, 0, 0] s[0:2] = 12
[1, 1, 2, 2, 0, 0, 0, 0] s[2:3] = 5
[1, 1, 2, 3, 0, 0, 0, 0] s[1:3] = 25
[1, 1, 2, 3, 3, 0, 0, 0] s[3:4] = 3
[1, 1, 2, 3, 3, 0, 0, 0] s[2:4] = 53
[1, 1, 2, 3, 3, 0, 0, 0] s[4:5] = 0
[1, 1, 2, 3, 3, 3, 0, 0] s[3:5] = 30
[1, 1, 2, 3, 3, 3, 3, 0] s[5:6] = 1
[1, 1, 2, 3, 3, 3, 3, 0] s[4:6] = 01
[1, 1, 2, 3, 3, 3, 3, 3] s[6:7] = 1
[1, 1, 2, 3, 3, 3, 3, 6] s[5:7] = 11
6
```
Starting from `i=1`, for each `i`, a number `s[i-1:i]` of length `one` is extracted. If it represents a valid card number, the current count `dp[i]` is updated by adding the previous count `dp[i-1]` calculated for the numbers from `s[0]` to `s[i-2]`. Next, a number of length 2, `s[i-2:i]`, is extracted. If it represents a valid card number, the current count `dp[i]` is updated by adding the previous count `dp[i-2]` calculated for the numbers from `s[0]` to `s[i-3]`. This process continues for each index `i`, updating the partial results in the `dp[]` array. Finally, the total count of possible cases is calculated by accessing the last element of the `dp[]` array.

The time complexity of the function is determined by the nested loops. The outer loop runs `n` times, and the inner loop runs at most 3 times for each iteration of the outer loop. Thus, the total number of iterations of the inner loop is bounded by `n*3`, which simplifies to $O(n)$. Since the operations inside the loops take constant time, the dominant factor in the time complexity is the nested loops. Therefore, the overall time complexity of the function is $O(n^2)$.
