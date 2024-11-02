a = list(map(int, input().split()))
ans = 0
for ai in a:
    if a.count(ai) >= 2:
        ans += 1
print(ans // 2)
