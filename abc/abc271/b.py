n, q = map(int, input().split())
seqs = [list(map(int, input().split()))[1:] for _ in range(n)]
for _ in range(q):
    s, t = map(int, input().split())
    print(seqs[s - 1][t-1])
