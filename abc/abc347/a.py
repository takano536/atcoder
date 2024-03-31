n, k = map(int, input().split())
ans = [int(num) // k for num in input().split() if int(num) % k == 0]
print(*ans)
