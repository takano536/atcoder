p = list(map(int, input().split()))

ans = ''
for i in p:
    ans += chr(ord('a') + i - 1)

print(ans)
