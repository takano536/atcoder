n, s = map(int, input().split())
t = [0] + list(map(int, input().split()))
is_satisfied = all((t[i + 1] - t[i] <= s for i in range(n)))
print('Yes' if is_satisfied else 'No')
