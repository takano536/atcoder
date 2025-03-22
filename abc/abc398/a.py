n = int(input())
ans = list('=' * (1 if n % 2 else 2))
while len(ans) < n:
    ans.append('-')
    ans.insert(0, '-')
print(''.join(ans))
