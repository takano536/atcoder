#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

int main() {
    std::map<char, std::pair<int, int>> DIRS = {
        {'D', {1, 0}},
        {'U', {-1, 0}},
        {'R', {0, 1}},
        {'L', {0, -1}},
    };

    int n;
    std::cin >> n;

    std::vector<std::vector<int>> ans(n, std::vector<int>(n, 0));
    std::pair<int, int> curr_pos = std::make_pair(0, 0);
    char curr_dir = 'R';
    for (int i = 1; i <= n * n; i++) {
        ans[curr_pos.first][curr_pos.second] = i;
        auto next = std::make_pair(curr_pos.first + DIRS[curr_dir].first, curr_pos.second + DIRS[curr_dir].second);
        if (next.first < 0) {
            curr_dir = 'R';
            next = std::make_pair(curr_pos.first + DIRS[curr_dir].first, curr_pos.second + DIRS[curr_dir].second);
        }
        if (next.first >= n) {
            curr_dir = 'L';
            next = std::make_pair(curr_pos.first + DIRS[curr_dir].first, curr_pos.second + DIRS[curr_dir].second);
        }
        if (next.second < 0) {
            curr_dir = 'U';
            next = std::make_pair(curr_pos.first + DIRS[curr_dir].first, curr_pos.second + DIRS[curr_dir].second);
        }
        if (next.second >= n) {
            curr_dir = 'D';
            next = std::make_pair(curr_pos.first + DIRS[curr_dir].first, curr_pos.second + DIRS[curr_dir].second);
        }
        if (ans[next.first][next.second] != 0) {
            switch (curr_dir) {
                case 'U':
                    curr_dir = 'R';
                    break;
                case 'R':
                    curr_dir = 'D';
                    break;
                case 'D':
                    curr_dir = 'L';
                    break;
                case 'L':
                    curr_dir = 'U';
                    break;
            }
            next = std::make_pair(curr_pos.first + DIRS[curr_dir].first, curr_pos.second + DIRS[curr_dir].second);
        }
        curr_pos = next;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (ans[i][j] == n * n) {
                std::cout << "T ";
            } else {
                std::cout << ans[i][j] << " ";
            }
        }
        std::cout << std::endl;
    }
}