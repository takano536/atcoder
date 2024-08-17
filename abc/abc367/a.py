a, b, c = map(int, input().split())
is_satisfied = True
curr = b
while True:
    if curr == c:
        break
    if curr == a:
        is_satisfied = False
        break
    curr = (curr + 1) % 24

print('Yes' if is_satisfied else 'No')
