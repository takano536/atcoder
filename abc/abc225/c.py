n, m = map(int, input().split())
prev_b = [int(num) - 1 for num in input().split()]
is_satisfied = all([prev_b[i + 1] % 7 - prev_b[i] % 7 == 1 for i in range(m - 1)])
is_satisfied &= all([prev_b[i + 1] - prev_b[i] == 1 for i in range(m - 1)])
for _ in range(n - 1):
    b = [int(num) - 1 for num in input().split()]
    is_satisfied &= all([b[i + 1] % 7 - b[i] % 7 == 1 for i in range(m - 1)])
    is_satisfied &= all([b[i + 1] - b[i] == 1 for i in range(m - 1)])
    is_satisfied &= all(b[i] - prev_b[i] == 7 for i in range(m))
    prev_b = b.copy()
print('Yes' if is_satisfied else 'No')
