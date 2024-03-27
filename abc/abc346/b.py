s = ''.join(['wbwbwwbwbwbw'] * 100)
n = len(s)
w, b = map(int, input().split())
l = 0
r = w + b
is_satisfied = False
for i in range(n - r):
    curr = s[l + i:r + i]
    if curr.count('w') == w and curr.count('b') == b:
        is_satisfied = True
print('Yes' if is_satisfied else 'No')
