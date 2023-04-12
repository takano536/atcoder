#include <iostream>
#include <map>
#include <set>

int main() {
    int n, q;
    std::cin >> n >> q;

    std::map<int, std::set<int>> graph;
    for (int i = 0; i < q; i++) {
        int t, a, b;
        std::cin >> t >> a >> b;
        a--, b--;

        switch (t) {
            case 1: {
                graph[a].insert(b);
                break;
            }
            case 2: {
                graph[a].erase(b);
                break;
            }
            case 3: {
                bool satisfies = graph[a].find(b) != graph[a].end() && graph[b].find(a) != graph[b].end();
                std::cout << (satisfies ? "Yes" : "No") << std::endl;
                break;
            }
            default: {
                return 1;
            }
        }
    }

    return 0;
}