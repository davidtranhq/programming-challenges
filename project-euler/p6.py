def sum_of_n(n):
    return 0.5*n*(n+1)

def sum_of_n_squares(n):
    return (1/6)*n*(n+1)*(2*n+1)

print(sum_of_n(100)**2 - sum_of_n_squares(100))