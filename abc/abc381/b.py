s = input()
n = len(s)

if n % 2 != 0:
    print('No')
    quit()

used = [False] * (ord('z') - ord('a') + 1)
for i in range(0, n, 2):
    if used[ord(s[i]) - ord('a')]:
        print('No')
        quit()
    if s[i] != s[i + 1]:
        print('No')
        quit()
    used[ord(s[i]) - ord('a')] = True

print('Yes')
