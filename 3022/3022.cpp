#include <iostream>
#include <map>

int main(int argc, const char *argv[]) {
    int N;
    std::cin >> N;
    std::map<std::string, int> pickup;
    std::string name;
    
    int ouch = 0;
    for (int i = 0; i < N; i++) {
        std::cin >> name;
        if (pickup.find(name) == pickup.end()) {
            pickup.insert({name, 1});
            continue;
        }
        int other_cookies = 0;

        for (auto &p : pickup) {
            if (p.first != name) {
                other_cookies += p.second;
            }
        }

        if (pickup[name] > other_cookies) {
            ouch++;
        }
        pickup[name]++;
    }

    std::cout << ouch;
    return 0;
}


