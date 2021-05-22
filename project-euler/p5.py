def divisible(n):
    for i in range(1, 21):
        if n % i:
            return False
    return True

x = 20
while True:
    if divisible(x):
        break
    x += 20
print(x)