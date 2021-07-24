from collections import defaultdict


d = defaultdict(int)
for _ in range(4):
    d[input()] += 1

for _, v in d.items():
    if v != 1:
        print('No')
        quit()
print('Yes')
