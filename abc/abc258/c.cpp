#include <iostream>
#include <string>

int main() {
    int n, q;
    std::cin >> n >> q;
    std::string s;
    std::cin >> s;

    int head_idx = 0;

    while (q--) {
        int t, x;
        std::cin >> t >> x;

        if (t == 1) {
            head_idx -= x;
            if (head_idx < 0) head_idx += n;
        } else {
            std::cout << s[(head_idx + x - 1) % n] << std::endl;
        }
    }

    return 0;
}