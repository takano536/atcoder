n, k = map(int, input().split())
a = [x - 1 for x in map(int, input().split())]
coords = list(tuple(map(int, input().split())) for _ in range(n))


def calc_dist(ai: tuple, aj: tuple): return (ai[0] - aj[0]) ** 2 + (ai[1] - aj[1]) ** 2


ans = 0
for i in range(len(coords)):
    min_lumi = 1e18
    for j in a:
        min_lumi = min(calc_dist(coords[i], coords[j]), min_lumi)
    ans = max(min_lumi, ans)

print(f'{ans ** (1 / 2):.6f}')
