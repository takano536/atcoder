n = int(input())
a = list(map(int, input().split()))
ans = 0
for num in a:
    ans += max(0, num - 10)
print(ans)
