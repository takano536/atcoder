n = int(input())
a = map(int, input().split())
k = int(input())
print(sum((k <= ai for ai in a)))
