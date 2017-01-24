#include <iostream>

long long combi(int n, int r) {
    long long res = 1;
    for (int i = 1; i <= r; i++) {
        res = res * (n-i+1) / i;
    }
    return res;
}
int main(int argc, const char *argv[])
{
    int T;
    std::cin >> T;
    int N, M;
    long long sols[T];
    for (int i = 0; i < T; i++) {
        std::cin >> N >> M;
        sols[i] = combi(M, N);
    }
    for (int i = 0; i < T; i++) {
        std::cout << sols[i] << "\n";
    }
    return 0;
}
