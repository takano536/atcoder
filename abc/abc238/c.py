MOD = 998244353
n = int(input())
ans = 0
curr = 0
while curr < n:
    curr += 1
    next = min(int(str(curr) + '0') - 1, n)
    cnt = next - curr + 1
    ans += cnt * (cnt + 1) // 2
    curr = next
print(ans % MOD)
