n, k = map(int, input().split())


def oct2int(num: int) -> int:
    ret = 0
    for i, c in enumerate(reversed(list(str(num)))):
        ret += int(c) * 8 ** i
    return ret


def int2nonal(num: int) -> int:
    ret = list()
    while num > 0:
        ret.append(str(num % 9))
        num //= 9
    return int(''.join(reversed(ret))) if len(ret) > 0 else 0


ans = n
for _ in range(k):
    ans = int2nonal(oct2int(ans))
    ans = int(str(ans).replace('8', '5'))
print(ans)
