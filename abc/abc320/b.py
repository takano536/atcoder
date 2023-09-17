s = input()
ans = 0
for i in range(len(s) + 1):
    for j in range(len(s) + 1):
        if i > j:
            continue
        if s[i:j] == ''.join(reversed(s[i:j])):
            ans = max(ans, j - i)
print(ans)
