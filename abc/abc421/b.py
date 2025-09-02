NA = -1
x, y = map(int, input().split())
z = int(''.join(reversed(list(str(x + y)))))
x, y, z = y, z, NA
for i in range(7):
    z = int(''.join(reversed(list(str(x + y)))))
    x, y, z = y, z, NA
print(y)
