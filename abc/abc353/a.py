n = int(input())
a = list(map(int, input().split()))
ans = -1
for i in range(1, n):
    if a[i] > a[0]:
        ans = i + 1
        break
print(ans)
