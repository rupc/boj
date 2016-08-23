#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct compare_member {
    bool operator() (const pair<int, string> &e1, const pair<int, string> &e2) {
        return e1.first < e2.first;
    }
};
int main(int argc, const char *argv[]) {
    int N;    
    cin >> N;
    vector<pair<int, string>> members(N);
    int t;
    string s;
    for (int i = 0; i < N; i++) {
        cin >> t >> s;
        members[i] = {t, s};
    }
    stable_sort(members.begin(), members.end(), compare_member());
    /*sort(members.begin(), members.end(),
        [](decltype(members)::value_type &e1, 
           decltype(members)::value_type &e2) {
            if (e1.first < e2.first) {
                return true;
            } else {
                return false;
            }
    });*/
    for (auto &p : members) {
        //printf("%d %s\n", p.first, p.second.c_str());
        cout << p.first << " " << p.second << "\n";
    }
    return 0;
}
