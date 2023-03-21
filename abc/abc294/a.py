input()
for a in map(int, input().split()):
    if a % 2:
        continue
    print(a, end=' ')
print('\n', end='')