s = ''.join(reversed(list(input())))

ans = 0
for i, c in enumerate(s):
    ans += 26 ** i * (ord(c) - ord('A') + 1)

print(ans)
