n = input()
t = input()
a = input()

for c1, c2 in zip(t, a):
    if c1 == c2 == 'o':
        print('Yes')
        quit()
print('No')
