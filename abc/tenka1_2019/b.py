n = int(input())
s = input()
k = int(input())
for c in s:
    print(c if c == s[k - 1] else '*', end='')
print()
