def func(k, n):
    ret = 0
    for i in range(1, len(str(n)) + 1):
        ret += int(n[-i]) * (k ** (i - 1))
    return ret


k = int(input())
a, b = input().split()
print(func(k, a) * func(k, b))
