def f(k): return 1 if k == 0 else k * f(k - 1)


print(f(int(input())))
