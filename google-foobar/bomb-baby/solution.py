'''
Notes:

bc even+odd = odd and odd+odd = even, if the numbers are (even,even) it is impossible
only coprime numbers are possible
order doesn't matter since starting numbers are the same, only need to search half the "tree"
numbers can never be the same except when 1=1 because (m,f) -> (m+f, f) or (m, m+f)

binary tree: define moving left on the tree as (m, f)->(m+f, f) and moving right as (m,f)->(m,m+f)
when moving left, m is greater; when moving right, f is greater

strategy: move backwards through the tree until (possibly) one number is 1
initialze (a,b) = (m,f)
if b > a, (a,b) -> (a, b%a)
if b < a, (a,b) -> (a%b, b)
increment the count by the quotient of max(a,b)/min(a,b)

once one number is 1, let the other number be x. you can get to (1,1) by taking x-1 steps

if a or b < 0 the return 'impossible'

'''

from fractions import gcd

def check_impossible(m, f, a, b):
    # if a common factor exists between the two numbers it's impossible
    if gcd(a, b) != 1:
        return True
    # check if both numbers are the same
    if m == f and m != '1' and f != '1':
        return True
    # check if both numbers are even
    even = ['0', '2', '4', '6', '8']
    if m[-1] in even and f[-1] in even:
        return True
    return False

def solution(m, f):
    a, b = long(m), long(f)
    if check_impossible(m,f,a,b):
        return 'impossible'
    gens = 0
    while a > 1 and b > 1:
        quot, remain = divmod(max(a,b), min(a,b))
        if a > b:
            a = remain
        elif a < b:
            b = remain
        else:
            return 'impossible'
        gens += quot
    if a < 1 or b < 1:
        return 'impossible'
    return str(gens + max(a,b)-1)

def generate(n):
    with open('data.txt', 'w') as out:
        for i in range(1, n):
            for j in range(1, i+1):
                s = solution(str(i), str(j))
                out.write('({},{}) = {}\n'.format(i,j,s))
