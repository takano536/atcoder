from collections import deque

s = input()
n = len(s)

deq = deque()
curr_char = s[0]
char_cnt = 0
for c in s:
    if c == curr_char:
        char_cnt += 1
    else:
        deq.append(char_cnt)
        curr_char = c
        char_cnt = 1
deq.append(char_cnt)

ans = n
while len(deq) > 1:
    left, right = deq[0], deq[-1]

    if left > right:
        ans = min(n - right, ans)
        deq.pop()
        deq[-1] += right
    else:
        ans = min(n - left, ans)
        deq.popleft()
        deq[0] += left

print(ans)
