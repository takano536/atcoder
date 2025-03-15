s = input()

curr = 'i'
ans = 0
i = 0
while i < len(s):
    c = s[i]
    if c != curr:
        ans += 1
    else:
        i += 1
    if curr == 'i':
        curr = 'o'
    elif curr == 'o':
        curr = 'i'

if (s[-1] == 'i'):
    ans += 1

print(ans)
