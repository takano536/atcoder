n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

ans = 0
for i, hero in enumerate(b):
    for j in [i, i + 1]:
        prev_a = a[j]
        a[j] = max(0, a[j] - hero)
        hero = max(0, hero - prev_a)
        ans += prev_a - a[j]

print(ans)
