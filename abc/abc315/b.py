m = int(input())
d = list(map(int, input().split()))

day_cumsum = d.copy()
for i in range(m - 1):
    day_cumsum[i + 1] += day_cumsum[i]

mid = int((sum(d) + 1) / 2)
month = 1
day = 1
for day_sum in range(day_cumsum[-1]):
    if day_sum == day_cumsum[month - 1]:
        month += 1
        day = 1
    if day_sum + 1 == mid:
        print(f'{month} {day}')
        break
    day += 1
