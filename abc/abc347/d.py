a, b, c = map(int, input().split())
c_bit = f'{c:b}'
c_pop_cnt = c_bit.count('1')
if (abs(a - b) + c_pop_cnt) % 2:
    print(-1)
    quit()
is_swapped = False
if a < b:
    is_swapped = True
    a, b = b, a

a_pop_cnt = (abs(a - b) + c_pop_cnt) // 2
b_pop_cnt = c_pop_cnt - a_pop_cnt
# print(a_pop_cnt, b_pop_cnt)
a_ans, b_ans = 0, 0
curr = len(c_bit) - 1
rev_c_bit = ''.join(reversed(c_bit))
while f'{a_ans:b}'.count('1') < a_pop_cnt:
    if curr < 0:
        print(-1)
        quit()
    if rev_c_bit[curr] == '1':
        a_ans += 1 << curr
    curr -= 1
# print(f'{a_ans:b}')
# print(c_bit)

while f'{b_ans:b}'.count('1') < b_pop_cnt:
    if curr < 0:
        print(-1)
        quit()
    if rev_c_bit[curr] == '1':
        b_ans += 1 << curr
    curr -= 1
# print(f'{b_ans:b}')
# print(c_bit)

curr = 0
while f'{a_ans:b}'.count('1') < a or f'{b_ans:b}'.count('1') < b:
    if curr >= len(c_bit) or rev_c_bit[curr] == '0':
        a_ans += 1 << curr
        b_ans += 1 << curr
    curr += 1
    if curr >= 60:
        break
if a_ans ^ b_ans != c:
    print(-1)
    quit()
if f'{a_ans:b}'.count('1') != a or f'{b_ans:b}'.count('1') != b:
    print(-1)
    quit()

if is_swapped:
    a_ans, b_ans = b_ans, a_ans
print(a_ans, b_ans)
# print(f'{a_ans:b}'.count('1'), f'{b_ans:b}'.count('1'), a_ans ^ b_ans)
# print(c_bit)
# print(f'{a_ans:b}')
# print(f'{b_ans:b}')
