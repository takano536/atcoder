TAX_RATE = 108
MAX_N = 50000

n = input()

for x in range(MAX_N + 1):
    if str(x * TAX_RATE)[:-2] == n:
        print(x)
        exit()

print(':(')
