k = 10000
divisor_sums = []
for i in range(10000):
    d_sum = 0
    for x in range(1, i):
        if not i % x:
            d_sum += (x + divisor_sums[x])
    divisor_sums.append(d_sum)
            
amicable_sum = 0
for ds in divisor_sums:
    if divisor_sums.index(ds) == divisor_sums[ds]:
        amicable_sum += (ds + divisor_sums[ds])
print(amicable_sum)
