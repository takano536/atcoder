n = int(input())
elems = tuple(input().split() for _ in range(n))
ans = ''
for c, l in elems:
    l = int(l)
    if len(ans) + l > 100:
        ans = 'Too Long'
        break
    ans += c * l
print(ans)
