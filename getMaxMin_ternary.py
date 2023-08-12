def get_max(a, b, c):
    if a > b:
        return a if a > c else c
    else:
        return b if b > c else c

def get_min(a, b, c):
    if a < b:
        return a if a < c else c
    else:
        return b if b < c else c

a, b, c = map(int, input("Input three integers: ").split())

max_val = get_max(a, b, c)
min_val = get_min(a, b, c)

print("Min =", min_val, "Max =", max_val)

