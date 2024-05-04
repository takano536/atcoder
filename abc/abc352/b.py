s = input()
t = input()

i = 0
ans = list()
for j, c in enumerate(t):
    if c == s[i]:
        ans.append(j + 1)
        i += 1

print(*ans)
