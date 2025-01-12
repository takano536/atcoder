#include <iostream>
#include <vector>

int main() {
    constexpr int INF = 1e9 + 1;
    constexpr int PARAM_NUM = 5;
    constexpr int FULL_PARAMS = (1 << PARAM_NUM) - 1;

    int n;
    std::cin >> n;

    std::vector params(n, std::vector<int>(PARAM_NUM));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < PARAM_NUM; j++) {
            std::cin >> params[i][j];
        }
    }

    auto vec2bit = [](const std::vector<std::vector<int>> &params, const int threshold) {
        const int N = params[0].size();

        std::vector<int> exists(1 << N);
        for (const auto &curr_params : params) {
            int bit = 0;
            for (int i = 0; i < N; i++) {
                if (curr_params[i] >= threshold) bit |= (1 << i);
            }
            exists[bit] = true;
        }

        std::vector<int> ret;
        for (int i = 0; i < (1 << N); i++) {
            if (exists[i]) ret.push_back(i);
        }

        return ret;
    };

    int ok = 0, ng = INF;
    while (ng - ok > 1) {
        const auto mid = (ok + ng) / 2;

        auto bitize_params = vec2bit(params, mid);
        bool is_satisfied = false;
        const int num = bitize_params.size();

        for (int i = 0; i < num; i++) {
            for (int j = 0; j < num; j++) {
                for (int k = 0; k < num; k++) {
                    int exceeded_params = 0;
                    exceeded_params |= bitize_params[i];
                    exceeded_params |= bitize_params[j];
                    exceeded_params |= bitize_params[k];
                    if (exceeded_params == FULL_PARAMS) is_satisfied = true;
                }
            }
        }

        (is_satisfied ? ok : ng) = mid;
    }

    std::cout << ok << std::endl;
    return 0;
}