n = input()
s = input()
t = input()

satisifies = True
for c1, c2 in zip(s, t):
    if c1 == c2:
        continue
    if c1 in '1l' and c2 in '1l':
        continue
    if c1 in '0o' and c2 in '0o':
        continue
    satisifies = False

print('Yes' if satisifies else 'No')
