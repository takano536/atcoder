n, x = map(int, input().split())
s = input()

stack = list()
curr = 'R' if x % 2 else 'L'
for c in s:
    stack += c
    while len(stack) >= 2 and (''.join(stack[-2:]) == 'RU' or ''.join(stack[-2:]) == 'LU'):
        stack.pop()
        stack.pop()
        continue

move = dict()
move['U'] = lambda x: int(x // 2)
move['L'] = lambda x: int(x * 2)
move['R'] = lambda x: int(x * 2 + 1)
for c in stack:
    x = move[c](x)
print(x)
