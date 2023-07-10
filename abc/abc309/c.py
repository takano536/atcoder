n, k = map(int, input().split())
meds = [tuple(map(int, input().split())) for _ in range(n)]

meds = sorted(meds)

ans = 1
med_idx = 0
total = sum([med[1] for med in meds])
while total > k and med_idx < n:
    ans = meds[med_idx][0] + 1
    total -= meds[med_idx][1]
    med_idx += 1

print(ans)
