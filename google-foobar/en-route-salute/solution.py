def solution(s):
    # leading < and trailing > will not encounter anyone before leaving the hallway
    s = s.lstrip('-<').rstrip('->')
    right = 0
    salutes = 0
    for c in s:
        if c == '>':
            right += 1
        elif c == '<':
            # the < will salute with every > so far
            salutes += right 
    return salutes*2