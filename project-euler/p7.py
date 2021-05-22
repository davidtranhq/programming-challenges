def is_prime(n):
    for i in range(2, int(n**0.5) + 1):
        if not n % i:
            return False
    return True

x = 3
i = 2
while i < 10001:
    x += 2
    if is_prime(x):
        i += 1
print(x)