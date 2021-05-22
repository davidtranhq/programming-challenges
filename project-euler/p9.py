def find_triple():
    for c in range(1000):
        for b in range(c):
            for a in range(b):
                if a**2 + b**2 == c**2 and a + b + c == 1000:
                    return a*b*c

print(find_triple())