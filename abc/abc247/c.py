def f(n: int) -> str:
    return ' '.join([f(n - 1), str(n), f(n - 1)]) if n > 1 else '1'


n = int(input())
print(f(n))
