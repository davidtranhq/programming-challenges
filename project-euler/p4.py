def is_palindrome(s):
    s = str(s)
    for i in range(len(s)//2 + 1):
        if s[i] != s[-(i+1)]:
            return False
    return True

pals = []
for i in range(999, 99, -1):
    for j in range(999, i-1, -1):
        prod = i * j
        if is_palindrome(prod):
            pals.append(prod)

print(max(pals))         
                
