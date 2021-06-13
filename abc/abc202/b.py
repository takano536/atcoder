s = ''.join(list(reversed(input())))

ans = ''
for c in s:
    if c == '6':
        ans += '9'
    elif c == '9':
        ans += '6'
    else:
        ans += c

print(ans)
