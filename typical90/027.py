n = int(input())
ids = set()
for i in range(n):
    s = input()
    if s in ids:
        continue
    print(i+1)
    ids.add(s)
