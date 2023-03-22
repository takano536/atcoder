n = int(input())

ans = 0
memo = [0] * n
for i in range(1, n):
    for j in range(1, n // i + 1):
        if i * j < n:
            memo[i * j] += 1

for ab in range(n):
    cd = n - ab
    if 0 in [ab, cd]:
        continue
    ans += memo[ab] * memo[cd]

print(ans)
