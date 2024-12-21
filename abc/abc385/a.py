a, b, c = map(int, input().split())

is_satisfied = (a == b == c)
is_satisfied |= (a + b == c)
is_satisfied |= (a == b + c)
is_satisfied |= (a + c == b)

print("Yes" if is_satisfied else "No")
