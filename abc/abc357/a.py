n, m = map(int, input().split())
h = list(map(int, input().split()))

ans = 0
for hi in h:
    m -= hi
    if m < 0:
        break
    ans += 1

print(ans)
