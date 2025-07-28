_, l, r = map(int, input().split())
print('Yes' if input()[l - 1:r] == 'o' * (r - l + 1) else 'No')
