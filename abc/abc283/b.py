n = int(input())
a = list(map(int, input().split()))

q = int(input())
for _ in range(q):
    query = list(map(int, input().split()))
    query[1] -= 1

    if len(query) == 3:
        a[query[1]] = query[2]
    if len(query) == 2:
        print(a[query[1]])
