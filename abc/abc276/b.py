n, m = map(int, input().split())
ans = [set() for _ in range(n)]
for _ in range(m):
    a, b = (id - 1 for id in map(int, input().split()))
    ans[a].add(b + 1)
    ans[b].add(a + 1)
for ids in ans:
    ids = sorted(ids)
    print(len(ids), *ids)
