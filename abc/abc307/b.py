n = int(input())
s = list(input() for _ in range(n))

satisfies = False
for i in range(n):
    for j in range(n):
        if i == j:
            continue
        sentence = s[i] + s[j]
        if sentence == ''.join(reversed(list(sentence))):
            satisfies = True
            break

print('Yes' if satisfies else 'No')
