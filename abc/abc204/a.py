x, y = map(int, input().split())
if x == y:
    print(x)
    quit()
te = [True] * 3
te[x], te[y] = False, False
for i in range(3):
    if te[i]:
        print(i)
