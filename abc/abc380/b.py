s = input()
a = [len(si) for si in s.split('|')]
print(*a[1:-1])
