#include <iostream>
#include <map>
#include <utility>
#include <vector>

int main() {
    const int TOP = 0;
    const int BTM = 1e9 + 1;
    const int NAN = 1e9 + 2;

    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto &ai : a) {
        std::cin >> ai;
    }
    a.insert(a.begin(), TOP);
    a.push_back(BTM);
    n += 2;

    std::map<int, int> heads, tails;
    for (int i = 0; i < n; i++) {
        heads[a[i]] = a[i] == TOP ? NAN : a[i - 1];
        tails[a[i]] = a[i] == BTM ? NAN : a[i + 1];
    }

    int ans_len = a.size() - 2;
    int q = 0;
    std::cin >> q;
    for (int i = 0; i < q; i++) {
        int query_type;
        std::cin >> query_type;
        if (query_type == 1) {
            int x, y;
            std::cin >> x >> y;
            heads[y] = x;
            tails[y] = tails[x];
            heads[tails[x]] = y;
            tails[x] = y;
            ans_len++;
        } else if (query_type == 2) {
            int x;
            std::cin >> x;
            heads[tails[x]] = heads[x];
            tails[heads[x]] = tails[x];
            heads.erase(x);
            tails.erase(x);
            ans_len--;
        }
    }

    std::vector<int> ans(ans_len);
    auto curr = tails[TOP];
    auto ans_iter = ans.begin();
    while (curr != BTM) {
        *ans_iter = curr;
        ans_iter++;
        curr = tails[curr];
    }

    for (int i = 0; i < ans_len; i++) {
        std::cout << ans[i] << ' ';
    }
    std::cout << std::endl;
    return 0;
}