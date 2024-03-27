s = list(input())
a, b = [int(num) - 1 for num in input().split()]
s[a], s[b] = s[b], s[a]
print(''.join(s))
