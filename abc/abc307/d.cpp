#include <algorithm>
#include <iostream>
#include <stack>
#include <string>

int main() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;

    std::stack<char> st;
    int left_bracket_cnt = 0;
    for (const auto &c : s) {
        st.push(c);
        if (st.top() == '(') {
            left_bracket_cnt++;
        }
        if (st.top() == ')' && left_bracket_cnt > 0) {
            while (st.top() != '(') {
                st.pop();
            }
            st.pop();
            left_bracket_cnt--;
        }
    }

    std::string ans;
    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }
    std::reverse(ans.begin(), ans.end());

    std::cout << ans << std::endl;
    return 0;
}