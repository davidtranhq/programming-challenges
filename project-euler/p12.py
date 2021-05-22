def factors(n):
    return set([x for pair in
        ((i, n//i) for i in range(2, int(n**0.5)+1) if not n % i) for x in pair])
    
def triangle_num(n):
    x = 0
    for i in range(n):
        x += i
    return x

n = 1
tri = 1
while len(factors(tri)) <= 500:
    n += 1
    tri = triangle_num(n)
print(tri)