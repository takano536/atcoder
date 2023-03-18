#include <bitset>
#include <iostream>

int main()
{
    int n;
    std::cin >> n;

    std::bitset<10> bin(n);
    std::cout << bin << std::endl;
}