#include <iostream>
#include <vector>

int main() {
    int n, t, m;
    std::cin >> n >> t >> m;

    std::vector<int> hates(n);    // bitで管理
    for (int i = 0; i < m; i++) {
        int a, b;
        std::cin >> a >> b;
        a--, b--;

        hates[a] |= (1 << b);    // aがbを嫌う
        hates[b] |= (1 << a);    // bがaを嫌う
    }

    int ans = 0;
    auto dfs = [&](auto dfs, std::vector<int> &team, int curr_player) -> void {
        int team_size = team.size();

        if (curr_player == n) {
            ans += static_cast<int>(team_size == t);
            return;
        }

        for (int i = 0; i < team_size; i++) {
            if (team[i] & (hates[curr_player])) {
                // curr_playerがteamの誰かと嫌いな場合
                continue;
            }
            auto next = team;
            next[i] |= (1 << curr_player);    // teamにcurr_playerを追加
            dfs(dfs, next, curr_player + 1);
        }

        if (team_size < t) {
            auto next = team;
            next.push_back(1 << curr_player);
            dfs(dfs, next, curr_player + 1);
        }

        return;
    };

    std::vector<int> team;
    dfs(dfs, team, 0);

    std::cout << ans << std::endl;
    return 0;
}