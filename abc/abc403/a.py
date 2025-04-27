n = int(input())
a = list(map(int, input().split()))
print(sum((a[i] for i in range(n) if i % 2 == 0)))
