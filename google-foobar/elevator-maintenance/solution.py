from functools import cmp_to_key

def compare(a, b):
    a = a.split('.')
    b = b.split('.')
    for i in range(0, min(len(a), len(b))):
        if a[i] != b[i]:
            break
    # if all numbers are the same, the longer list is bigger
    if a[i] == b[i]:
        if len(a) < len(b):
            return -1
        elif len(b) < len(a):
            return 1
        else:
            return 0
    else:
        return int(a[i]) - int(b[i])

def solution(li):
    return sorted(li, key=cmp_to_key(compare))

'''
"Technically" the above is all that's needed... but the fun part of this challenge is actually implementing a sorting algorithm. Here's a solution that manually implements quicksort:

def partition(li, begin, end):
    pivot = li[end]
    # [begin, i] will be less than the pivot (left partition)
    # [i, j] will be greater than the pivot (right partition)
    i = 0
    j = 0
    while j < end:
        if compare(li[j], pivot) > 0:
            # keep this element in the right partition
            j += 1
        else:
            # swap this element with the leftmost element in the right
            # partition and increment the divider (i) so it becomes the left part
            li[i], li[j] = li[j], li[i]
            i += 1
            j += 1
    # finally, swap the pivot with the leftmost element in the right part
    li[end], li[i] = li[i], li[end]
    return i



def qsort(li, begin, end):
    if begin < end:
        pivot = partition(li, begin, end)
        qsort(li, begin, pivot-1)
        qsort(li, pivot+1, end)

def solution(li):
    qsort(li, 0, len(li)-1)
    return li
'''