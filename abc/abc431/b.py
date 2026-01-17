ans = int(input())
n = int(input())
w = list(map(int, input().split()))

has_attached = [False] * n
for _ in range(int(input())):
    p = int(input())
    p -= 1
    ans += -w[p] if has_attached[p] else w[p]
    has_attached[p] = not has_attached[p]
    print(ans)
