MOD = int(1e9 + 7)

n = int(input())
c = sorted(list(map(int, input().split())))

ans = 1
for i in range(n):
    ans *= (c[i] - i)
    ans %= MOD

print(ans)
