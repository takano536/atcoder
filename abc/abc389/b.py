x = int(input())

ans = 1
num = 1
while True:
    ans += 1
    num *= ans
    if x == num:
        print(ans)
        break
