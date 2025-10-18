s = input()
n = len(s)
for i, c in enumerate(s):
    if i != (n + 1) // 2 - 1:
        print(c, end='')
print('\n', end='')
