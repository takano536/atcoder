C = ('Red', 'Green', 'Blue')
prices = {C[i]: p for i, p in enumerate(map(int, input().split()))}
prices.pop(input())
print(min(prices.values()))
