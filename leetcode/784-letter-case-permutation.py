from typing import List

def changeCase(s: str, i: int) -> str:
    return s[:i] + s[i].swapcase() + s[i+1:]

def letterCasePermutation(s: str) -> List[str]:
    i = 0
    char_indices = [i for i, c in enumerate(s) if c.isalpha()]
    perms = [s]
    for i in char_indices:
        new_perms = []
        for p in perms:
            new_perm = changeCase(p, i)
            new_perms.append(new_perm)
        perms += new_perms
    return perms
