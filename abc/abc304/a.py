n = int(input())
s, a = list(), list()
for _ in range(n):
    si, ai = input().split()
    s.append(si)
    a.append(int(ai))

min_a = 1e18
min_idx = 0
for i, age in enumerate(a):
    if age < min_a:
        min_a = age
        min_idx = i

i = min_idx
cnt = 0
while cnt != n:
    print(s[i])
    i = (i + 1) % n
    cnt += 1
