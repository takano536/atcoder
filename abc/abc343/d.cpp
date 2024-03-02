#include <iostream>
#include <map>
#include <vector>

int main() {
    int n, t;
    std::cin >> n >> t;

    std::vector<int> a(t), b(t);
    for (int i = 0; i < t; i++) {
        std::cin >> a[i] >> b[i];
        a[i]--;
    }

    std::map<int, long long> scores;
    std::map<long long, int> players;
    for (int i = 0; i < n; i++) {
        scores[i] = 0;
        players[0]++;
    }
    for (int i = 0; i < t; i++) {
        players[scores[a[i]]]--;
        if (players[scores[a[i]]] == 0) {
            players.erase(scores[a[i]]);
        }
        scores[a[i]] += b[i];
        players[scores[a[i]]]++;
        std::cout << players.size() << std::endl;
    }
    return 0;
}