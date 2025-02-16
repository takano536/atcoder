a = list(map(int, input().split()))
sorted_a = list(range(1, len(a) + 1))

for i in range(len(a) - 1):
    swaped_a = a.copy()
    swaped_a[i], swaped_a[i + 1] = swaped_a[i + 1], swaped_a[i]
    if swaped_a == sorted_a:
        print('Yes')
        exit()
print('No')
