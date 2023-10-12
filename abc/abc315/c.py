n = int(input())
ices = [list(map(int, input().split())) for _ in range(n)]
sorted_ices = sorted([(ice[1], ice[0]) for ice in ices], reverse=True)

max_scores = [list() for _ in range(n + 1)]
for score, flavor in sorted_ices:
    max_scores[flavor].append((score, flavor))

ans = 0
for scores in max_scores:
    if len(scores) < 2:
        continue
    ans = max(scores[0][0] + int(scores[1][0] / 2), ans)

best_ice_score, best_ice_flavor = max([ice for ice in sorted_ices])
for ices in max_scores:
    if len(ices) == 0:
        continue
    score, flavor = ices[0]
    if flavor == best_ice_flavor:
        continue
    ans = max(ices[0][0] + best_ice_score, ans)

print(ans)
