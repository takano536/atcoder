x, y = map(int, input().split())

ans = 0
num = x
while 1:
    if num > y:
        break
    ans += 1
    num *= 2

print(ans)
