n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
ans = [0, 0]
for a_num, b_num in zip(a, b):
    ans[0] += a_num == b_num
for a_num in a:
    ans[1] += a_num in b
ans[1] -= ans[0]
print('\n'.join([str(cnt) for cnt in ans]))
