n, d = map(int, input().split())
s = ''.join(reversed(input()))
ans = ''
for c in s:
    if c == '@' and d > 0:
        ans += '.'
        d -= 1
    else:
        ans += c

print(''.join(reversed(ans)))
