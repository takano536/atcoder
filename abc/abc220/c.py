import math

n = int(input())
a = list(map(int, input().split()))
x = int(input())

ans = math.floor(x / sum(a)) * n
sum = math.floor(x / sum(a)) * sum(a)
for i in a:
    if sum > x:
        break
    sum += i
    ans += 1
    if sum > x:
        break
print(ans)
