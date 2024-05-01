n, x = map(int, input().split())
print(''.join([chr(ord('A') + i) * n for i in range(0, 26 + 1)])[x - 1])
