x, c = map(int, input().split())

ans = 0
for i in range(1000, x + 1, 1000):
    fee = i // 1000 * c
    if i + fee > x:
        break
    ans = i

print(ans)
