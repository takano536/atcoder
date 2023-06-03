#include <iostream>
#include <queue>
#include <vector>

int main() {
    int n, d;
    std::cin >> n >> d;
    d *= d;

    std::vector<int> x(n), y(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> x[i] >> y[i];
    }

    std::vector<bool> is_infected(n);
    is_infected[0] = true;

    std::queue<int> infected_persons;
    infected_persons.push(0);

    while (!infected_persons.empty()) {
        int infected_person = infected_persons.front();
        infected_persons.pop();

        for (int i = 0; i < n; ++i) {
            if (is_infected[i]) {
                continue;
            }
            if ((x[i] - x[infected_person]) * (x[i] - x[infected_person]) + (y[i] - y[infected_person]) * (y[i] - y[infected_person]) <= d) {
                is_infected[i] = true;
                infected_persons.push(i);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        std::cout << (is_infected[i] ? "Yes" : "No") << std::endl;
    }
    return 0;
}