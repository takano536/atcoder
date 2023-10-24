n, q = map(int, input().split())
a = list(map(int, input().split()))
a_dict = dict()
for i, num in enumerate(a):
    if a_dict.get(num) is None:
        a_dict[num] = [i + 1]
    else:
        a_dict[num].append(i + 1)
for _ in range(q):
    x, k = map(int, input().split())
    print(-1 if a_dict.get(x) is None or k > len(a_dict[x]) else a_dict[x][k - 1])
