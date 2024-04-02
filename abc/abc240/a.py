N = 10
satisfied_pairs = {(i + 1, i + 2) for i in range(N - 1)}
satisfied_pairs |= {(i + 2, i + 1) for i in range(N - 1)}
satisfied_pairs |= {(1, 10), (10, 1)}
print('Yes' if tuple(map(int, input().split())) in satisfied_pairs else 'No')
