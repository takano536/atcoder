#include <iostream>
#include <limits>
#include <string>
#include <vector>

using namespace std;

// https://algo-logic.info/segment-tree/
/* RMQ：[0,n-1] について、区間ごとの最小値を管理する構造体
    update(a,b,x): 区間[a,b) の要素を x に更新。O(log(n))
    query(a,b): [a,b) での最小の要素を取得。O(log(n))
*/
template <typename T>
struct RMQ {
    const T INF = numeric_limits<T>::max();
    int n;
    vector<T> dat, lazy;
    RMQ(int n_)
        : n(), dat(n_ * 4, INF), lazy(n_ * 4, INF) {
        int x = 1;
        while (n_ > x)
            x *= 2;
        n = x;
    }

    /* lazy eval */
    void eval(int k) {
        if (lazy[k] == INF)
            return;       // 更新するものが無ければ終了
        if (k < n - 1) {  // 葉でなければ子に伝搬
            lazy[k * 2 + 1] = lazy[k];
            lazy[k * 2 + 2] = lazy[k];
        }
        // 自身を更新
        dat[k] = lazy[k];
        lazy[k] = INF;
    }

    void update(int a, int b, T x, int k, int l, int r) {
        eval(k);
        if (a <= l && r <= b) {  // 完全に内側の時
            lazy[k] = x;
            eval(k);
        } else if (a < r && l < b) {                     // 一部区間が被る時
            update(a, b, x, k * 2 + 1, l, (l + r) / 2);  // 左の子
            update(a, b, x, k * 2 + 2, (l + r) / 2, r);  // 右の子
            dat[k] = min(dat[k * 2 + 1], dat[k * 2 + 2]);
        }
    }
    void update(int a, int b, T x) {
        update(a, b, x, 0, 0, n);
    }

    T query_sub(int a, int b, int k, int l, int r) {
        eval(k);
        if (r <= a || b <= l) {  // 完全に外側の時
            return INF;
        } else if (a <= l && r <= b) {  // 完全に内側の時
            return dat[k];
        } else {  // 一部区間が被る時
            T vl = query_sub(a, b, k * 2 + 1, l, (l + r) / 2);
            T vr = query_sub(a, b, k * 2 + 2, (l + r) / 2, r);
            return min(vl, vr);
        }
    }
    T query(int a, int b) {
        return query_sub(a, b, 0, 0, n);
    }

    /* debug */
    inline T operator[](int a) {
        return query(a, a + 1);
    }
    void print() {
        for (int i = 0; i < 2 * n - 1; ++i) {
            cout << (*this)[i];
            if (i != n)
                cout << ",";
        }
        cout << endl;
    }
};

int main() {
    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    RMQ<int> is_lower(n);
    for (int i = 0; i < n; i++) {
        is_lower.update(i, i + 1, std::islower(s[i]));
    }

    int q;
    std::cin >> q;
    for (int i = 0; i < q; i++) {
        int t, x;
        char c;
        std::cin >> t >> x >> c;
        x--;

        switch (t) {
            case 1: {
                s[x] = c;
                if (std::islower(c)) {
                    is_lower.update(x, x + 1, true);
                } else {
                    is_lower.update(x, x + 1, false);
                }
                break;
            }
            case 2: {
                is_lower.update(0, n, true);
                break;
            }
            case 3: {
                is_lower.update(0, n, false);
                break;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (is_lower[i]) {
            std::cout << static_cast<char>(std::tolower(s[i]));
        } else {
            std::cout << static_cast<char>(std::toupper(s[i]));
        }
    }
    std::cout << std::endl;
    return 0;
}