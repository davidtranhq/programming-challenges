# Let 0 denote a downwards movement and 1 denote a rightwards movement.
# A string of 0's and 1's describes the path taken through the lattice.
# Because the player starts at (0,0) and must end at (n,n), the string will always have a length of 2n.
# The number of 0s and 1s in the string must be equal.
# (2n)!/(n!)*!r

def fac(n):
    x = 1
    for i in range(1, n+1):
        x *= i
    return x

def lattice_paths(n):
    return fac(2*n) / (fac(n)*fac(n))

print(lattice_paths(2))

print(lattice_paths(20))