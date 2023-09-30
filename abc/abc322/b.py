n, m = map(int, input().split())
s = input()
t = input()

is_suffix = t.endswith(s)
is_prefix = t.startswith(s)

ans = 3
if is_suffix and is_prefix:
    ans = 0
elif is_prefix:
    ans = 1
elif is_suffix:
    ans = 2

print(ans)
