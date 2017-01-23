#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
int min_cost = std::numeric_limits<int>::max();
int cost;
int get_rgb_dist(int line, int color, std::vector<std::vector<int>> &cc);

int main(int argc, const char *argv[]) {
    int N;
    std::cin >> N;
    std::vector<std::vector<int>> color_costs(N+1, std::vector<int>(3, 0));
    for (int i = 1; i <= N; i++) {
        std::cin >> color_costs[i][0];
        std::cin >> color_costs[i][1];
        std::cin >> color_costs[i][2];
    }
    int res = std::min(
            {get_rgb_dist(1, 0, color_costs),
             get_rgb_dist(1, 1, color_costs),
             get_rgb_dist(1, 2, color_costs)
            });
    std::cout << res << "\n";
    return 0;
}


// line : {1 ... N}, color : {0, 1, 2}
int get_rgb_dist(int line, int color, std::vector<std::vector<int>> &cc) {
    cost += cc[line][color];
    if (line == cc.size()-1) {
        if (min_cost > cost) {
            min_cost = cost;
        }
        cost -= cc[line][color];
        return -1;
    }
    if (color == 0) {
        get_rgb_dist(line + 1, 1, cc);
        get_rgb_dist(line + 1, 2, cc);
    } else if (color == 1) {
        get_rgb_dist(line + 1, 0, cc);
        get_rgb_dist(line + 1, 2, cc);
    } else {
        get_rgb_dist(line + 1, 0, cc);
        get_rgb_dist(line + 1, 1, cc);
    }
    cost -= cc[line][color];
    return min_cost;
}
