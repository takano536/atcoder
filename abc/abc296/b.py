s = [input() for _ in range(8)]

alphabets = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h']

for i, r in enumerate(s):
    if not '*' in r:
        continue
    num = str(len(s) - i)
    for j, c in enumerate(r):
        if c == '*':
            alphabet = alphabets[j]

print(alphabet + num)