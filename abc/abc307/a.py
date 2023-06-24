n = int(input())
a = list(map(int, input().split()))
ans = 0
for i, ai in enumerate(a):
    ans += ai
    if (i + 1) % 7 == 0:
        print(ans)
        ans = 0
