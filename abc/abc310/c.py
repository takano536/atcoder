n = int(input())
s = [input() for _ in range(n)]
reversed_s = [''.join(reversed(list(balls))) for balls in s]
print(len(set([balls if balls < reversed_balls else reversed_balls for balls, reversed_balls in zip(s, reversed_s)])))
