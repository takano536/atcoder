n = int(input())
s = [input() for _ in range(n)]

marks = ['H', 'D', 'C', 'S']
numbers = ['A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K']
cards = [mark + number for number in numbers for mark in marks]

satisifies = len(set(s)) == len(s) and all([card in cards for card in s])
print('Yes' if satisifies else 'No')
