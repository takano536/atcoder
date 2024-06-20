n, m = map(int, input().split())
s = [int(input().replace('o', '1').replace('x', '0'), 2) for _ in range(n)]

ans = 0
for i in range(n):
    for j in range(n):
        if i == j:
            continue
        if s[i] | s[j] == (1 << m) - 1:
            ans += 1

print(ans // 2)
