l1, r1, l2, r2 = map(int, input().split())
is_colored = [False] * 101
ans = 0
for i in range(l1, r1):
    is_colored[i] = True
for i in range(l2, r2):
    ans += is_colored[i]
print(ans)
