i, j = map(int, input().split('-'))
j += 1
if j == 9:
    i += 1
    j = 1
print(f'{i}-{j}')
