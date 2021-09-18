s = list()
for i in range(3):
    s.append(input())
t = int(''.join(list(reversed(input()))))

while (t > 0):
    i = t % 10
    print(s[i - 1], end='')
    t //= 10
