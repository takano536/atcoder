a, b = map(int, input().split())
ans = 0
for i in range(1000):
    if abs(a - b * i) < abs(a - b * ans):
        ans = i
print(ans)
