n = input()
a = list(map(int, input().split()))

ans = 1
for num in a:
    ans *= num
    if ans > 1e18:
        ans = -1
        break

print(0 if 0 in a else ans)
