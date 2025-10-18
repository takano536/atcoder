n = int(input())
a = list(map(int, input().split()))

ans = n + 1 - 2

for i in range(n):
    if a[i] == 1:
        break
    ans -= 1

for i in range(n - 1, -1, -1):
    if a[i] == 1:
        break
    ans -= 1

print(max(ans, 0))
