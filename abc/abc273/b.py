x, k = map(int, input().split())


def myround(x, i):
    n = len(str(x))
    left = int(f'{x // 10 ** (i + 1):<0{n}d}')
    right = int(str(x % 10 ** (i + 1)))
    return left + 10 ** len(str(right)) if 5 <= int(str(right)[0]) < 10 else left


for i in range(k):
    x = myround(x, i)

print(x)
