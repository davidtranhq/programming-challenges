def is_prime(n):
    for i in range(2, int(n**0.5) + 1):
        if not n % i:
            return False
    return True

sum = 2
for i in range(3, 2000000, 2):
    if is_prime(i):
        sum += i
print(sum)