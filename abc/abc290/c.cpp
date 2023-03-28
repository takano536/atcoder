#include <iostream>
#include <vector>
#include <map>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    std::map<int, int> num_cnts; 
    for (auto &num : a) {
        std::cin >> num;
        num_cnts[num]++;
    }

    int ans;
    for (ans = 0; ans < k; ans++) {
        if (num_cnts[ans] == 0) {
            break;
        }
    }

    std::cout << ans << std::endl;
}