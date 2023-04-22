n = int(input())
s = input()

ans = -1
level = 0
for _ in range(2):
    for i in range(n - 1):
        if s[i] == 'o':
            level += 1
        if s[i] != s[i + 1] and s[i + 1] == '-':
            ans = max(level, ans)
            level = 0
    level = 0
    s = ''.join(list(reversed(s)))

print(ans)
