s = input()
ans = list(s)
has_used = False
exists_sharp = False
for i, c in enumerate(s):
    if c == '#':
        if has_used:
            exists_sharp = True
        continue
    if not has_used:
        ans[i] = 'o'
        has_used = True
    if has_used and exists_sharp:
        ans[i] = 'o'
        exists_sharp = False

print(''.join(ans))
