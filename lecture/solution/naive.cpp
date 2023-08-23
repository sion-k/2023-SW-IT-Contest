#include <bits/stdc++.h>

#define FAST() cin.tie(0)->sync_with_stdio(0)

using namespace std;

bool collapse(int s1, int e1, int s2, int e2) {
    if (e1 <= s2 || e2 <= s1) {
        return false;
    }

    return true;
}

int main() {
    FAST();

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> r(n + 1);
    for (int i = 0; i < m; i++) {
        int k, s, e;
        cin >> k >> s >> e;

        bool flag = false;
        for (auto [s1, e1] : r[k]) {
            if (collapse(s, e, s1, e1)) {
                flag = true;
                break;
            }
        }

        if (flag) {
            cout << "NO" << '\n';
        } else {
            cout << "YES" << '\n';
            r[k].emplace_back(s, e);
        }
    }
}
