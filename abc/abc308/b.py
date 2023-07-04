n, m = map(int, input().split())

c = list(input().split())
d = list(input().split())
p = list(map(int, input().split()))

prices = dict(zip(d, p[1:]))

ans = 0
for key in c:
    ans += (p[0] if key not in prices else prices[key])

print(ans)
