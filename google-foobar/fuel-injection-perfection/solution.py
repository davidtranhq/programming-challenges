def solution(s):
    x = int(s)
    steps = 0
    # divide when even, odd numbers alternate between +1 and -1 for their most optimal solution
    # +1 to numbers with LSB of 01, -1 to numbers with LSB of 11 (recurs every 4th number)
    # exception: 3 is better to subtract (3->2->1 vs 3->4->2->1)
    while x > 1:
        if not x % 2:
            x /= 2
        else:
            if x % 4 == 1 or x == 3:
                x -= 1
            else:
                x += 1
        steps += 1
    return steps
