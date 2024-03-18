#include <algorithm>
#include <cassert>
#include <iostream>
#include <numeric>
#include <utility>
#include <vector>

struct Tile {
    int h, w;
    bool is_flipped;

    Tile()
        : h(0), w(0), is_flipped(false) {
    }
    Tile(int h, int w)
        : h(h), w(w), is_flipped(false) {
    }
    Tile(int h, int w, bool is_flipped)
        : h(h), w(w), is_flipped(is_flipped) {
    }
};

bool is_fillable(const std::pair<int, int> &cell_size, const std::vector<Tile> &tiles);
bool is_puttable(std::vector<std::vector<bool>> &is_covered, const Tile &tile);
std::vector<Tile> sort_tiles(std::vector<Tile> &tiles, const std::vector<int> &idxes);

int main() {
    int n, h, w;
    std::cin >> n >> h >> w;
    std::vector<Tile> tiles(n);
    for (auto &tile : tiles) {
        std::cin >> tile.h >> tile.w;
    }

    std::vector<int> idxes(n);
    std::iota(idxes.begin(), idxes.end(), 0);

    bool is_satisfied = false;

    do {
        auto putting_tiles = sort_tiles(tiles, idxes);
        for (int bit = 0; bit < (1 << n); bit++) {
            for (int i = 0; i < n; i++) {
                putting_tiles[i].is_flipped = (bit & (1 << i));
            }
            is_satisfied |= is_fillable({h, w}, putting_tiles);
        }
    } while (std::next_permutation(idxes.begin(), idxes.end()));

    std::cout << (is_satisfied ? "Yes" : "No") << std::endl;
    return 0;
}

bool is_fillable(const std::pair<int, int> &cell_size, const std::vector<Tile> &tiles) {
    std::vector cells(cell_size.first, std::vector<bool>(cell_size.second));
    for (const auto &tile : tiles) {
        const auto tile_h = tile.is_flipped ? tile.w : tile.h;
        const auto tile_w = tile.is_flipped ? tile.h : tile.w;
        if (!is_puttable(cells, {tile_h, tile_w})) {
            return false;
        }
    }
    for (int i = 0; i < cell_size.first; i++) {
        if (std::ranges::all_of(cells[i], [](bool is_covered) { return is_covered; }) == false) {
            return false;
        }
    }
    return true;
}

bool is_puttable(std::vector<std::vector<bool>> &is_covered, const Tile &tile) {
    const int h = is_covered.size();
    const int w = is_covered[0].size();
    auto putted_cells = is_covered;

    std::pair<int, int> putting_idx = {-1, -1};
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (!is_covered[i][j]) {
                putting_idx = {i, j};
                break;
            }
        }
        if (putting_idx.first != -1) {
            break;
        }
    }
    if (putting_idx.first == -1) {
        return true;
    }

    for (int i = putting_idx.first; i < putting_idx.first + tile.h; i++) {
        for (int j = putting_idx.second; j < putting_idx.second + tile.w; j++) {
            if (i < 0 || i >= h || j < 0 || j >= w || is_covered[i][j]) {
                return false;
            }
            putted_cells[i][j] = true;
        }
    }
    is_covered = putted_cells;
    return true;
}

std::vector<Tile> sort_tiles(std::vector<Tile> &tiles, const std::vector<int> &idxes) {
    auto ret = tiles;
    int n = tiles.size();
    for (int i = 0; i < n; i++) {
        ret[i] = tiles[idxes[i]];
    }
    return ret;
}