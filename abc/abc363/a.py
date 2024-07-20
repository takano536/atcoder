r = int(input())
for i in range(100, 400 + 1, 100):
    if i > r:
        print(i - r)
        break
