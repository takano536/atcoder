n = int(input())
a = list(map(int, input().split()))
nums = sorted([(num, i) for i, num in enumerate(a)], reverse=True)
print(nums[1][1] + 1)
