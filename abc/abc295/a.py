n = input()
print("Yes" if any([s in ["and", "not", "that", "the", "you"] for s in input().split()]) else "No")