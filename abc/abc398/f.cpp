#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class RollingHash {
    using ull = unsigned long long;
    using u128 = __uint128_t;

    const ull MOD = (1ULL << 61) - 1;  // 2^61-1が安全で高速らしい
    const ull BASE = 37;               // MODの原始根のひとつ

    std::vector<ull> hash, power;

  public:
    RollingHash(const std::string &s) {
        const int n = s.size();
        hash.resize(n + 1, 0);
        power.resize(n + 1, 1);

        for (int i = 0; i < n; i++) {
            power[i + 1] = mod_mul(power[i], BASE);
            hash[i + 1] = mod_add(mod_mul(hash[i], BASE), s[i]);
        }
    }

    unsigned long long get_hash(int l, int r) {
        // s[l:r] のハッシュ値を取得（0-based, ex: s[0:1] は s[0] のみ）
        return mod_sub(hash[r], mod_mul(hash[l], power[r - l]));
    }

  private:
    ull mod_add(ull lhs, ull rhs) {
        return (lhs + rhs) % MOD;
    }

    ull mod_sub(ull lhs, ull rhs) {
        return (lhs >= rhs) ? (lhs - rhs) : (lhs + MOD - rhs);
    }

    ull mod_mul(ull lhs, ull rhs) {
        return static_cast<ull>(static_cast<u128>(lhs) * rhs % MOD);
    }
};

int main() {
    std::string s;
    std::cin >> s;

    const int n = s.size();
    RollingHash rh(s);

    auto rev_s = s;
    std::ranges::reverse(rev_s);
    RollingHash rev_rh(rev_s);

    auto is_palindrome = [&](int l, int r) -> bool {
        return rh.get_hash(l, r) == rev_rh.get_hash(n - r - 1, n - l - 1);
    };

    int l;
    for (l = 0; l < n; l++) {
        if (is_palindrome(l, n - 1)) break;
    }

    std::string ans = s;
    for (int i = l - 1; i >= 0; i--) ans += s[i];

    std::cout << ans << std::endl;
    return 0;
}