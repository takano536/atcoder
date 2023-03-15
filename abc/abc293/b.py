n = int(input())
a = [int(num) - 1 for num in input().split()]

is_called = [False] * n
for i, num in enumerate(a):
    if not is_called[i]:
        is_called[num] = True

print(f"{n - sum(is_called)}\n{' '.join([str(i + 1) for i, ok in enumerate(is_called) if not ok])}")
