s = input()

ans = 1 + int(s[-1])
prev = int(s[-1])
for c in s[-2::-1]:
    num = int(c)
    ans += 1
    ans += int(c) - prev
    if int(c) - prev < 0:
        ans += 10
    prev = int(c)

print(ans)
