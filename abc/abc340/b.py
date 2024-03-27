vec = list()
size = 0
q = int(input())
for i in range(q):
    query = list(map(int, (input().split())))
    if query[0] == 1:
        vec.append(query[1])
        size += 1
    else:
        print(vec[size - query[1]])
