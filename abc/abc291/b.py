n = int(input())
x = list(map(int, input().split()))

x.sort()

print(sum(x[n:-n]) / len(x[n:-n]))