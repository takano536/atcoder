n = int(input())
addresses = tuple((str(i + 1), input()) for i in range(n))
print('Yes' if tuple(input().split()) in addresses else 'No')
