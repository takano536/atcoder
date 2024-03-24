n, m = map(int, input().split())
is_stopped = {name: False for name in input().split()}
for name in input().split():
    is_stopped[name] = True
for _, is_satisfied in is_stopped.items():
    print('Yes' if is_satisfied else 'No')
