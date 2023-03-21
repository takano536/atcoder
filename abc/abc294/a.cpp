#include <iostream>

int main()
{
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        std::cin >> a;
        if (a % 2) {
            continue;
        }

        std::cout << a << ' ';
    }
    std::cout << std::endl;
    return 0;
}