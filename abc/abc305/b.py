DISTS = [3, 1, 4, 1, 5, 9, 0]
IDS = ['A', 'B', 'C', 'D', 'E', 'F', 'G']

p, q = input().split()
min_id = min(IDS.index(p), IDS.index(q))
max_id = max(IDS.index(p), IDS.index(q))
print(sum(DISTS[min_id:max_id]))
