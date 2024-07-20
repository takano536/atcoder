#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
    long long n;
    std::cin >> n;

    std::vector<int> ans;
    for (int i = 0; i <= 9; i++) {
        ans.push_back(i);
    }
    for (int i = 11; i <= 99; i += 11) {
        ans.push_back(i);
    }
    if (n <= 19) {
        std::cout << ans[n - 1] << std::endl;
        return 0;
    }

    std::vector<long long> pows;
    long long pow = 1;
    for (int i = 0; i < 18; i++) {
        pows.push_back(pow);
        pow *= 10;
    }

    std::vector<long long> idxes;
    long long prev = 1;
    long long curr = 9;
    int cnt = 1;
    while (curr < 1e18) {
        idxes.push_back(curr - prev);
        idxes.push_back(curr - prev);
        cnt++;
        prev *= 10;
        curr = std::stoll(std::string(cnt, '9'));
    }
    idxes[0] += 2, idxes[1]++;

    int i = 0;
    long long total = 0;
    for (i = 0; i < static_cast<int>(idxes.size()); i++) {
        if (n - idxes[i] < 0) break;
        n -= idxes[i];
        total += idxes[i];
    }
    long long num = pows[i / 2] + n - (i - 1);
    int digit = i + 1;
    std::string num_str = std::to_string(num);

    std::string reversed_num_str = num_str;
    std::ranges::reverse(reversed_num_str);

    int curr_digit = num_str.size();
    int curr_idx = digit % 2;
    while (curr_digit < digit) {
        num_str += reversed_num_str[curr_idx];
        curr_digit++;
        curr_idx++;
    }
    std::cout << num_str << std::endl;
    return 0;
}