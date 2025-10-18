OS = {'Ocelot': 0, 'Serval': 1, 'Lynx': 2}
x, y = input().split()
print('Yes' if OS[x] >= OS[y] else 'No')
