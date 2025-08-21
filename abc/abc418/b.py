s = input()
ans = 0
for i in range(len(s)):
    if s[i] != 't':
        continue
    for j in range(i + 1, len(s)):
        if s[j] != 't':
            continue
        if j - i + 1 < 3:
            continue
        count = s[i:j + 1].count('t')
        ans = max((count - 2) / (j - i + 1 - 2), ans)

print('{:.10f}'.format(ans))
