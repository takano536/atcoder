n, k = map(int, input().split())
ans = 0
total = 0
while True:
    total += n
    if total >= k:
        break
    n += 1
    ans += 1
print(ans)
