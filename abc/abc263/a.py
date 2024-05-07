cards = sorted(list(map(int, input().split())))
is_satisfied = True
is_satisfied = len(set(cards)) == 2
is_satisfied &= cards.count(cards[0]) in (2, 3) and cards.count(cards[-1]) in (2, 3)
print('Yes' if is_satisfied else 'No')
