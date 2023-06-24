n = int(input())
a = list(map(int, input().split()))
print(' '.join([str(sum(a[i*7:(i+1)*7])) for i in range(n)]))
