s = [input() for _ in range(8)]

alphabets = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h']
alphabet, num = str(), str()

for i, r in enumerate(s):
    if '*' not in r:
        continue
    num = str(len(s) - i)
    for j, c in enumerate(r):
        if c == '*':
            alphabet = alphabets[j]

ans = "".join([alphabet, num])
print(ans)
