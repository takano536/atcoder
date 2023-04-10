x = int(input())

ans = 0
for i in range(1, x + 1):
    ans += i * 10000

print(ans // x)
