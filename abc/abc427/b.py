n = int(input())
ans = 1
for i in range(n - 1):
    for c in str(ans):
        ans += int(c)
print(ans)
