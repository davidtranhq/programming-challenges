def find_factors(n):
    '''Returns a sorted list containing the factors of n'''
    # search for factor pairs by finding one factor and dividing n by it to get the other
    # only need to search up to sqrt(n) because higher factors are paired with lower ones
    return sorted(set(x for tup in ([i, n//i] 
        for i in range(1, int(n**0.5)+1) if not n % i) for x in tup))

def valid_sequence(s, seq):
    '''Returns true if s is entirely composed of consecutive instances of seq'''
    seqlen = len(seq)
    for i in range(0, len(s), seqlen):
        if s[i:i+seqlen] != seq:
            # there was a mismatch; this is not a valid sequence
            return False
    # every substring matched; this is a valid sequence
    return True

def solution(s):
    # only substrings that are factors of len(s) leave no leftovers
    factors = find_factors(len(s))
    # because factors are sorted in increasing order, the smallest subdivision
    # will be found first (maximum number of slices)
    for f in factors:
        # the potential sequence starts from the beginning and is f long
        seq = s[:f]
        if valid_sequence(s, seq):
            return len(s)/f
    # the cake can't be sliced (1 "part")
    return 1
        
