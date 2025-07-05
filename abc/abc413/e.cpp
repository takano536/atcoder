#include <algorithm>
#include <iostream>
#include <vector>

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(1 << n);
    for (auto &ai : a) std::cin >> ai;

    std::vector<std::vector<int>> chunks;
    for (int i = 0; i < (1 << n); i += 2) {
        chunks.push_back({std::min(a[i], a[i + 1]), std::max(a[i], a[i + 1])});
    }

    std::vector<std::vector<int>> next_chunks;
    while (chunks.size() > 1) {
        for (size_t i = 0; i < chunks.size(); i += 2) {
            if (chunks[i] > chunks[i + 1]) std::swap(chunks[i], chunks[i + 1]);
            chunks[i].insert(chunks[i].end(), chunks[i + 1].begin(), chunks[i + 1].end());
            next_chunks.push_back(chunks[i]);
        }
        chunks = std::move(next_chunks);
        next_chunks.clear();
    }

    for (const auto &pi : chunks[0]) std::cout << pi << ' ';
    std::cout << '\n';
}

int main() {
    int t;
    std::cin >> t;

    while (t--) solve();

    std::cout << std::flush;
    return 0;
}