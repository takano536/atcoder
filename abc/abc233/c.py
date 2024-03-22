def count(idx: int, prod: int, a: list, x: int) -> int:
    if idx == len(a):
        return int(prod == x)
    ans = 0
    for num in a[idx]:
        ans += count(idx + 1, prod * num, a, x)
    return ans


def main():
    n, x = map(int, input().split())
    a = [list(map(int, input().split()))[1:] for _ in range(n)]
    print(count(0, 1, a, x))


if __name__ == '__main__':
    main()
