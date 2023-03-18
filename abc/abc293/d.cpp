#include <iostream>
#include <vector>

#include <atcoder/dsu>

int main()
{
    int n, m;
    std::cin >> n >> m;

    atcoder::dsu union_find(n);
    int circular_count = 0;
    for (int i = 0; i < m; i++) {
        int a, c;
        char b, d;
        std::cin >> a >> b >> c >> d;
        a--, c--;
        if (union_find.leader(a) == union_find.leader(c)) {
            circular_count++;
        }
        union_find.merge(a, c);
    }

    int group_count = union_find.groups().size();
    std::cout << circular_count << ' ' << group_count - circular_count << std::endl;
}