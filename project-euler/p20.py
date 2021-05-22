def fac(n):
    prod = 1
    for x in range(2, n+1):
        prod *= x
    return prod

s = str(fac(100))
sum = 0
for ch in s:
    sum += int(ch)
print(sum)