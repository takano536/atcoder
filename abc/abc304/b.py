n = input()

print(n[:3], end='')
if len(n) > 3:
    for _ in range(len(n) - 3):
        print('0', end='')
