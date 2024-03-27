x, y = map(int, input().split())
ans = 0
while x < y:
    ans += 1
    x += 10
print(ans)
