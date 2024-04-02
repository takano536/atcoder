n, k = map(int, input().split())
print(*[int(num) // k for num in input().split() if int(num) % k == 0])
