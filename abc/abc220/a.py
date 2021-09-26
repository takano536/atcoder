a, b, c = map(int, input().split())
for ans in range(a, b + 1):
    if ans % c == 0:
        print(ans)
        quit()
print(-1)
