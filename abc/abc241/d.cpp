#include <iostream>
#include <set>

int main() {
    int q;
    std::cin >> q;
    std::multiset<long long> asc, desc;
    for (int query = 0; query < q; query++) {
        int opt;
        std::cin >> opt;
        switch (opt) {
            case 1: {
                long long x;
                std::cin >> x;
                asc.insert(x);
                desc.insert(-x);
                break;
            }
            case 2: {
                long long x;
                int k;
                std::cin >> x >> k;
                k--;
                std::multiset<long long>::iterator iter;
                int cnt;
                for (iter = desc.lower_bound(-x), cnt = 0; iter != desc.end() && cnt < k; iter++, cnt++) {
                }
                std::cout << (iter == desc.end() ? -1 : -*iter) << std::endl;
                break;
            }
            case 3: {
                long long x;
                int k;
                std::cin >> x >> k;
                k--;
                std::multiset<long long>::iterator iter;
                int cnt;
                for (iter = asc.lower_bound(x), cnt = 0; iter != asc.end() && cnt < k; iter++, cnt++) {
                }
                std::cout << (iter == asc.end() ? -1 : *iter) << std::endl;
                break;
            }
            default: {
                exit(-1);
            }
        }
    }
    return 0;
}