n = int(input())
s = list(input() for _ in range(n))

strs = set()
for i in range(n):
    for j in range(n):
        if i == j:
            continue
        strs.add(s[i] + s[j])

print(len(strs))
