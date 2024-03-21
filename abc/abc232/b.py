s = input()
t = input()
print('Yes' if len({(ord(c1) - ord(c2)) % 26 for c1, c2 in zip(s, t)}) == 1 else 'No')
