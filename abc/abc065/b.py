n = int(input())
a = [int(input()) for _ in range(n)]

is_pushed = [False] * n
ans = 0

curr_idx = 0
satisfied = False
while not is_pushed[curr_idx]:
    is_pushed[curr_idx] = True
    ans += 1
    curr_idx = a[curr_idx] - 1
    if curr_idx == 1:
        satisfied = True
        break

print(ans if satisfied else -1)
