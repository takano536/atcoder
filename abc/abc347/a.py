n, k = map(int, input().split())
a = [int(num) // k for num in input().split() if int(num) % k == 0]
for ans in a:
    print(ans, end=' ')
print()
