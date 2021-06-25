n = int(input())
ans = n
s = set([])
for i in range(2, int(1e5)):
    for j in range(2, 100):
        pow_num = int(pow(i, j))
        if pow_num > n:
            break
        s.add(pow_num)
print(ans - len(s))
