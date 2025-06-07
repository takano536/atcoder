n = int(input())
a = list(map(int, input().split()))

ans = a[0]
for x in range(1, 200):
    count = 0
    for ai in a:
        if ai >= x:
            count += 1
    if count >= x:
        ans = x
print(ans)
