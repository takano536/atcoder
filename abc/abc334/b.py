a, m, l, r = map(int, input().split())

l -= a
r -= a

ans = 0
if l * r < 0:
    ans += 1
    ans += r // m
    ans += -l // m
elif l < 0:
    ans += -l // m
    ans -= -r // m
    if -r % m == 0:
        ans += 1
elif l > 0:
    ans += r // m
    ans -= l // m
    if l % m == 0:
        ans += 1

print(ans)
