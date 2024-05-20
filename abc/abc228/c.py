MAX_SCORE = 300

n, k = map(int, input().split())
p_scores = [(sum(list(map(int, input().split()))), i) for i in range(n)]

sorted_p_scores = sorted(p_scores, reverse=True)
kth_score, _ = sorted_p_scores[k - 1]
ans = ['No'] * n

for i, p in enumerate(sorted_p_scores):
    p_score, id = p
    if i + 1 <= k or p_score + MAX_SCORE >= kth_score:
        ans[id] = 'Yes'

print(*ans, sep='\n')
