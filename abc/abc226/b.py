n = int(input())
seqs = set()
for _ in range(n):
    a = list(input().split())[1:]
    seqs.add(' '.join(a))

print(len(seqs))
