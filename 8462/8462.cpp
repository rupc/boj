#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

int main(int argc, const char *argv[])
{
    int n, t;
    std::cin >> n >> t;
    std::vector<int> vi(n);

    for (int i = 0; i < n; i++) {
        std::cin >> vi[i];
    }

    int l, r;
    std::vector<std::pair<int, int>> queries(t);
    for (int i = 0; i < t; i++) {
        std::cin >> l >> r;
        queries[i] = {l, r};
    }
    std::sort(queries.begin(), queries.end());
    std::sort(queries.begin(), queries.end(), [](std::pair<int, int> &lhs, std::pair<int, int> &rhs){
            if (lhs.second < rhs.second) {
                return true;
            } else return false;
    });

    for (auto &p : queries) {
        std::cout << p.first << " " << p.second << "\n";
    }

    return 0;

}
