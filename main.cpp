#include <iostream>
#include <cstdio>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    long long cur = 0;
    int dir = 1;
    set<long long> req;

    while (n--) {
        string op;
        cin >> op;
        if (op == "add") {
            long long x;
            cin >> x;
            req.insert(x);
        } else if (op == "cancel") {
            long long x;
            cin >> x;
            req.erase(x);
        } else if (op == "action") {
            if (req.empty()) continue;
            if (dir == 1) {
                auto it = req.upper_bound(cur);
                if (it != req.end()) {
                    cur = *it;
                    req.erase(it);
                } else {
                    dir = -1;
                    it = req.lower_bound(cur);
                    if (it == req.begin()) {
                        cur = *it;
                        req.erase(it);
                    } else {
                        --it;
                        cur = *it;
                        req.erase(it);
                    }
                }
            } else {
                auto it = req.lower_bound(cur);
                if (it != req.begin()) {
                    --it;
                    cur = *it;
                    req.erase(it);
                } else {
                    dir = 1;
                    it = req.upper_bound(cur);
                    cur = *it;
                    req.erase(it);
                }
            }
        } else {
            cout << cur << '\n';
        }
    }
    return 0;
}
