# keep track of which numbers have been visited and don't bother computing the
# sequence for those ones (because their sequence will be a subset)

def collatz(n):
    seq = {n}
    while n > 1:
        if not n % 2:
            n /= 2
        else:
            n = 3*n + 1
        seq.add(n)
    return seq

exclude = set()
longest = 0
longest_n = 0
for n in range(1, 1000000):
    if n in exclude:
        continue
    seq = collatz(n)
    if len(seq) > longest:
        longest_n = n
        longest = len(seq)
    exclude |= seq
print(longest_n)