n, k = map(int, input().split())
a = list(map(int, input().split()))

ans = 1
for ai in a:
    if ai >= 10 ** k:
        ans = 1
        continue
    ans *= ai
    if ans >= 10 ** k:
        ans = 1

print(ans)
