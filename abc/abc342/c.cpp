#include <iostream>
#include <string>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    int q;
    std::cin >> q;

    std::string hash_map = "abcdefghijklmnopqrstuvwxyz";
    int hash_map_size = hash_map.size();
    for (int i = 0; i < q; i++) {
        char c, d;
        std::cin >> c >> d;
        for (int j = 0; j < hash_map_size; j++) {
            if (hash_map[j] == c) {
                hash_map[j] = d;
            }
        }
    }

    for (auto c : s) {
        std::cout << hash_map[c - 'a'];
    }
    std::cout << std::endl;

    return 0;
}