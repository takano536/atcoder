#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <string>
#include <vector>

const int SOLID_COUNT = 2;

//_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

class Timer {
  public:
    Timer() {
        start = std::chrono::system_clock::now();
    }
    int64_t get_elapsed() {
        const auto end = std::chrono::system_clock::now();
        return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    }

  private:
    std::chrono::system_clock::time_point start;
};

//_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

class CorrectnessJudger {
    typedef std::vector<std::vector<std::string>> Input;
    typedef std::vector<std::vector<int>> Output;

  public:
    CorrectnessJudger(const Input &f, const Input &r) {
        d = f.size();
        this->f = f;
        this->r = r;
    }

    bool satisfies(const Output &b) {
        Input f(SOLID_COUNT, std::vector<std::string>(d));
        Input r(SOLID_COUNT, std::vector<std::string>(d));

        for (int i = 0; i < SOLID_COUNT; i++) {
            for (int x = 0; x < d; x++) {
                for (int y = 0; y < d; y++) {
                    for (int z = 0; z < d; z++) {
                        int id = b[i][x * d * d + y * d + z];
                        if (id == 0) {
                            continue;
                        }

                        f[z][x] = '1';
                        r[z][y] = '1';
                    }
                }
            }
        }

        return f == this->f && r == this->r;
    }

  private:
    int d;
    Input f, r;
};

//_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

class Solver {
    typedef std::vector<std::vector<std::string>> Input;
    typedef std::vector<std::vector<int>> Output;

  public:
    Solver() {
        std::cin >> d;
        n = 0;

        Input f(SOLID_COUNT, std::vector<std::string>(d));
        Input r(SOLID_COUNT, std::vector<std::string>(d));
        for (int i = 0; i < SOLID_COUNT; i++) {
            for (auto &str : f[i]) {
                std::cin >> str;
            }
            for (auto &str : r[i]) {
                std::cin >> str;
            }
        }

        this->f = f;
        this->r = r;
    }

    void create_base() {
        Output b(SOLID_COUNT, std::vector<int>(d * d * d));

        for (int i = 0; i < SOLID_COUNT; i++) {
            int id = 0;
            for (int x = 0; x < d; x++) {
                for (int y = 0; y < d; y++) {
                    for (int z = 0; z < d; z++) {
                        if (this->f[i][z][x] == '0' || this->r[i][z][y] == '0') {
                            continue;
                        }
                        id++;
                        b[i][x * d * d + y * d + z] = id;
                    }
                }
            }
            this->n = std::max(id, this->n);
        }

        this->b = b;
    }

    void prune() {
        Input f(SOLID_COUNT, std::vector<std::string>(d, std::string(d, '0')));
        Input r(SOLID_COUNT, std::vector<std::string>(d, std::string(d, '0')));
        this->n = -1;

        std::vector<std::vector<int>> coordinates(3, std::vector<int>(d));
        for (auto &vec : coordinates) {
            std::iota(vec.begin(), vec.end(), 0);
        }

        std::random_device seed_generator;
        std::mt19937 rng(seed_generator());
        for (auto &vec : coordinates) {
            std::shuffle(vec.begin(), vec.end(), rng);
        }

        for (int i = 0; i < SOLID_COUNT; i++) {
            for (const auto &x : coordinates[0]) {
                for (const auto &y : coordinates[1]) {
                    for (const auto &z : coordinates[2]) {
                        int id = this->b[i][x * d * d + y * d + z];
                        if (id == 0) {
                            continue;
                        }

                        if (f[i][z][x] == '1' && r[i][z][y] == '1') {
                            this->b[i][x * d * d + y * d + z] = 0;
                            continue;
                        }

                        f[i][z][x] = '1';
                        r[i][z][y] = '1';
                    }
                }
            }

            int curr_block_id = 0;
            for (auto &num : b[i]) {
                if (num == 0) {
                    continue;
                }
                curr_block_id++;
                num = curr_block_id;
            }
            this->n = std::max(curr_block_id, this->n);
        }
    }

    void merge() {
    }

    void output() {
        std::cout << this->n << std::endl;
        for (const auto &vec : this->b) {
            for (const auto num : vec) {
                std::cout << num << ' ';
            }
            std::cout << std::endl;
        }
    }

  private:
    int d;
    int n;
    Input f, r;
    Output b;
};

//_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

int main() {
    Timer timer;

    Solver solver;
    solver.create_base();

    solver.prune();

    solver.output();
    return 0;
}