s = input()
n = len(s)

ans = 0
for i in range(n):
    for j in range(i + 1, n):
        for k in range(j + 1, n):
            if j - i != k - j:
                continue
            if s[i] != 'A' or s[j] != 'B' or s[k] != 'C':
                continue
            ans += 1

print(ans)
