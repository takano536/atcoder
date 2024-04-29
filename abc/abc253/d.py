import math

n, a, b = map(int, input().split())
n_sum = n * (n + 1) // 2


def calc_sum(n: int, a: int, d: int) -> int:
    return n * (2 * a + (n - 1) * d) // 2


n_sum = n * (n + 1) // 2
a_sum = calc_sum(n // a, a, a)
b_sum = calc_sum(n // b, b, b)
ab_sum = calc_sum(n // math.lcm(a, b), math.lcm(a, b), math.lcm(a, b))

print(n_sum - (a_sum + b_sum - ab_sum))
