n = int(input())
a = tuple(map(int, input().split()))

ans = [0] * n
has_visited = [False] * n
curr = 1
for i in range(n):
    max_score = 0
    idxes = []
    for j in range(n):
        if has_visited[j]:
            continue
        if max_score < a[j]:
            max_score = a[j]
            idxes = [j]
        elif max_score == a[j]:
            idxes.append(j)
    for idx in idxes:
        ans[idx] = curr
        has_visited[idx] = True
    curr += len(idxes)
print(*ans, sep="\n")
