class Solution:
    # return s with the case of the ith character swapped
    def changeCase(self, s: str, i: int) -> str:
        return s[:i] + s[i].swapcase() + s[i+1:]

    def letterCasePermutation(self, s: str) -> List[str]:
        # indices that point to characters in the string
        i = 0
        char_indices = [i for i, c in enumerate(s) if c.isalpha()]
        # total permutations visited
        perms = [s]
        for i in char_indices:
            # permutations for the current character
            new_perms = []
            for p in perms:
                new_perm = self.changeCase(p, i)
                new_perms.append(new_perm)
            perms += new_perms
        return perms
            
                
            
            