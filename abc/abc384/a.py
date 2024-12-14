n, c1, c2 = input().split()
s = input()
n = int(n)

for c in s:
    print(c2 if c != c1 else c, end='')
print()
