s = input()

ans = 0
for c in s:
    ans += 1 if c == 'v' else 2

print(ans)