BAD_CELLS = (['#.', '.#'], ['.#', '#.'])
s = [input() for _ in range(2)]
print('Yes' if s not in BAD_CELLS else 'No')
