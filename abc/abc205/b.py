n = int(input())
a = list(map(int, input().split()))
cnt = [0] * 1010
for num in a:
    cnt[num] += 1

for i in range(1, 1000 + 1):
    if cnt[i] > 1:
        print('No')
        quit()
print('Yes')
