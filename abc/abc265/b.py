n, m, t = map(int, input().split())
a = list(map(int, input().split()))
bonuses = {x - 1: y for x, y in [tuple(map(int, input().split())) for _ in range(m)]}

is_satisfied = True
for i, ai in enumerate(a, 1):
    if t - ai <= 0:
        is_satisfied = False
    t -= ai
    bonus = bonuses.get(i)
    if bonus is not None:
        t += bonus

print('Yes' if is_satisfied else 'No')
