n, d, p = map(int, input().split())
f = sorted(list(map(int, input().split())), reverse=True)

fees = list()
fee_sum = 0
fee_cnt = 0
for fee in f:
    fee_sum += fee
    fee_cnt += 1
    if fee_cnt == d:
        fees.append(fee_sum)
        fee_cnt = 0
        fee_sum = 0
if fee_sum > 0:
    fees.append(fee_sum)

print(sum([p if fee > p else fee for fee in fees]))
