s, a, b, x = map(int, input().split())

ans = 0
time = 0
for i in range(x):
    time += 1
    ans += (s if time <= a else 0)
    if time == a + b:
        time = 0

print(ans)
