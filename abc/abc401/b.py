n = int(input())

ans = 0
is_logout = True
for i in range(n):
    s = input()
    if s == 'logout':
        is_logout = True
    elif s == 'login':
        is_logout = False
    elif s == 'private' and is_logout:
        ans += 1

print(ans)
