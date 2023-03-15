s = input()
ans = str()
for i in range(0, len(s), 2):
    ans += s[i + 1] + s[i]
print(ans)
