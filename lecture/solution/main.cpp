#include <bits/stdc++.h>

#define FAST() cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main() {
    FAST();

    int n, m;
    cin >> n >> m;

    vector<int> r(n + 1);
    for (int i = 0; i < m; i++) {
        int k, s, e;
        cin >> k >> s >> e;

        if (r[k] <= s) {
            cout << "YES" << '\n';
            r[k] = e;
        } else {
            cout << "NO" << '\n';
        }
    }
}
