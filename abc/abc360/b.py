s, t = input().split()

for i in range(1, len(s)):
    for j in range(i):
        substr = ''
        for k in range(j, len(s), i):
            substr += s[k]
        if substr == t:
            print('Yes')
            exit()
print('No')
