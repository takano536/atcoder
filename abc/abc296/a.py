n = int(input())
s = input()
satisfies = True

if n == 1:
    print('Yes')
    quit()

for i in range(n - 1):
    if s[i] == s[i + 1]:
        satisfies = False

print('Yes' if satisfies else 'No')