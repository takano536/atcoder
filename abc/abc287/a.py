n = int(input())
print("Yes" if [input() for _ in range(n)].count("For") > n // 2 else "No")