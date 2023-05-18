def sieve_of_eratosthenes(x):
    nums = [i for i in range(x+1)]

    root = int(pow(x, 0.5))
    for i in range(2, root + 1):
        if nums[i] != 0:
            for j in range(i, x + 1):
                if i * j >= x + 1:
                    break
                nums[i * j] = 0

    primes = sorted(list(set(nums)))[2:]

    return primes


def main():
    LR_MAX = int(1e5)

    cumsum = [0] * (LR_MAX + 1)
    primes = sieve_of_eratosthenes(LR_MAX)
    for i in range(1, LR_MAX + 1):
        if i % 2 == 0:
            continue
        if i in primes and (i + 1) / 2 in primes:
            cumsum[i] = 1

    for i in range(1, LR_MAX):
        cumsum[i + 1] += cumsum[i]

    q = int(input())
    l, r = [inputs for inputs in zip(*[map(int, input().split()) for _ in range(q)])]

    for left, right in zip(l, r):
        print(cumsum[right] - cumsum[left - 1])


if __name__ == '__main__':
    main()
