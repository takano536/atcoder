n = int(input())
d = list(map(int, input().split()))

ans = 0
for month, end in enumerate(d, 1):
    for day in range(1, end + 1):
        month_str, day_str = str(month), str(day)
        used = [False] * 10
        for c in month_str:
            used[int(c)] = True
        for c in day_str:
            used[int(c)] = True
        if sum(used) == 1:
            ans += 1

print(ans)
