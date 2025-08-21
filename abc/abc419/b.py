q = int(input())
balls = list()
for _ in range(q):
    inputs = list(map(int, input().split()))
    if inputs[0] == 1:
        balls.append(inputs[1])
    if inputs[0] == 2:
        print(min(balls))
        balls.remove(min(balls))
