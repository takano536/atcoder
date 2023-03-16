#include <iostream>
#include <string>
#include <utility>

int main()
{
    std::string s;
    std::cin >> s;

    std::string ans = s;
    int len = std::size(s);
    for (int i = 0; i < len; i += 2)
        std::swap(ans[i], ans[i + 1]);
    
    std::cout << ans << std::endl;
}