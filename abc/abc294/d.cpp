#include <algorithm>
#include <iostream>
#include <numeric>
#include <set>

int main()
{
    int n, q;
    std::cin >> n >> q;

    std::set<int> not_called_people, called_people;
    for (int i = 1; i <= n; i++) {
        not_called_people.insert(i);
    }

    int e, x;
    for (int i = 0; i < q; i++) {
        std::cin >> e;

        switch (e) {
            case 1: {
                auto p = *not_called_people.begin();
                not_called_people.erase(not_called_people.begin());
                called_people.insert(p);
                break;
            }

            case 2: {
                std::cin >> x;
                called_people.erase(x);
                break;
            }

            case 3: {
                if (!called_people.empty()) {
                    std::cout << *called_people.begin() << std::endl;
                }
                break;
            }
        }
    }

    return 0;
}