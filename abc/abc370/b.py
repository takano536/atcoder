n = int(input())
a = [list(map(int, input().split())) for _ in range(n)]

ans = 0
for j in range(n):
    ans = (a[ans][j] if ans >= j else a[j][ans]) - 1

print(ans + 1)
