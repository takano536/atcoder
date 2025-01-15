n = int(input())
ans = sum(tuple(0 <= sum(tuple(map(int, input().split()))) < 20 for _ in range(n)))
print(ans)
