n = int(input())
cnt = 0
for i in range(int(1e9)):
    cnt += i
    if cnt >= n:
        print(i)
        quit()
