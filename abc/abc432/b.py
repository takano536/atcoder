x = input()

char_cnts = [0] * 10
for i in range(0, 10):
    char_cnts[i] = x.count(str(i))

for i in range(1, 10):
    if char_cnts[i] == 0:
        continue
    print(i, end='')
    char_cnts[i] -= 1
    break

for i in range(0, 10):
    if char_cnts[i] == 0:
        continue
    print(str(i) * char_cnts[i], end='')
print('\n', end='')
