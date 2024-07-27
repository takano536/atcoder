n, x, y = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

foods_a = sorted([(a[i], b[i]) for i in range(n)], reverse=True)
foods_b = sorted([(b[i], a[i]) for i in range(n)], reverse=True)

curr_a, curr_b = 0, 0
for i in range(n):
    curr_a += foods_a[i][0]
    curr_b += foods_b[i][0]
    if curr_a > x or curr_b > y:
        print(i + 1)
        quit()

print(n)
