n = int(input())
for _ in range(n):
    a = list(map(int, input().split()))
    ans = [i + 1 for i, is_connected in enumerate(a) if is_connected]
    print(' '.join(map(str, ans)))
