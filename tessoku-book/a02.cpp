#include <iostream>

int main()
{
    int n, x;
    std::cin >> n >> x;
    bool exists = false;
    for (int i = 0; i < n; i++) {
        int a;
        std::cin >> a;
        if (a == x) {
            exists = true;
        }
    }

    std::cout << (exists ? "Yes" : "No") << std::endl;
}