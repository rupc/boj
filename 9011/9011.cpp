#include <iostream>
#include <vector>
#include <list>
int main(int argc, const char *argv[]) {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        std::vector<int> nums(n);
        std::vector<int> sol(n);
        std::vector<int> eli;
        bool err_flg = false;
        for (int i = 0; i < n; i++) {
            scanf("%d", &nums[i]);
            eli.push_back(i+1);
        }
        for (int i = n-1; i >= 0; i--) {
            if (nums[i] >= eli.size()) {
                err_flg = true;
                break;
            }
            sol[i] = *(eli.begin() + nums[i]);
            eli.erase(eli.begin() + nums[i]);
        }
        if (!err_flg) {
            for (auto &p : sol) {
                printf("%d ", p);
            }
        } else {
            printf("IMPOSSIBLE");
        }
        printf("\n");
    }
    return 0;
}


