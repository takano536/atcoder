n = int(input())
s = input()

for i in range(n - 1):
    ans = 0
    for j in range(n - (i + 1)):
        if s[j] == s[(i + 1) + j]:
            break
        ans += 1
    print(ans)
