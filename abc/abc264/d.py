atcoder = 'atcoder'
idxes = list(atcoder.find(c) for c in input())
ans = 0
for i, idx in enumerate(idxes):
    for j in range(i + 1, len(atcoder)):
        if idx > idxes[j]:
            ans += 1

print(ans)
