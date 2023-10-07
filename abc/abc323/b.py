n = int(input())

players = []
for i in range(n):
    players.append((input().count('x'), i + 1))

players.sort()
for player in players:
    print(player[1], end=' ')
print()
