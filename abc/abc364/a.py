n = int(input())
s = [input() for _ in range(n)]
is_satisfied = True
for i in range(n - 2):
    if s[i] == s[i + 1] and s[i] == 'sweet':
        is_satisfied = False
        break

print('Yes' if is_satisfied else 'No')
