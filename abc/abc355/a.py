x = set(map(int, input().split()))
if len(x) == 1:
    print(-1)
    quit()

for i in range(1, 3 + 1):
    if i in x:
        continue
    print(i)
    break
