#include <iostream>

int main(int argc, const char *argv[])
{
    int N;
    std::cin >> N;
    long long fib[N+1];
    fib[0] = 0;
    fib[1] = 1;
    fib[2] = 1;
    if (N < 3) {
        std::cout << fib[N];
    }
    for (int i = 3; i <= N; i++) {
        fib[i] = fib[i-2] + fib[i-1];
    }
    std::cout << fib[N];
    return 0;
}
