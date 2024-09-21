m = int(input())
ans = list()
while m > 0:
    i = 0
    while 3 ** i <= m and i <= 10:
        i += 1
    ans.append(i - 1)
    m -= 3 ** (i - 1)
print(len(ans))
print(*ans)
