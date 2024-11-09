n, k = map(int, input().split())
s = list(input())

ans = 0
for i in range(n - k + 1):
    if s[i:i + k] == list('O' * k):
        s[i:i + k] = list('X' * k)
        ans += 1
print(ans)
