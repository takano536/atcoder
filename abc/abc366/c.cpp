#include <iostream>
#include <map>

int main() {
    int q;
    std::cin >> q;

    std::map<int, int> box;
    while (q--) {
        int opt;
        std::cin >> opt;

        switch (opt) {
            case 1: {
                int x;
                std::cin >> x;
                box[x]++;
                break;
            }
            case 2: {
                int x;
                std::cin >> x;
                box[x]--;
                if (box[x] == 0) box.erase(x);
                break;
            }
            case 3: {
                std::cout << box.size() << std::endl;
                break;
            }
        }
    }
    return 0;
}