#include <bits/stdc++.h>

#define FAST() cin.tie(0)->sync_with_stdio(0)

using namespace std;

const int MOD = 1e9 + 7;

int n, m, k;
vector<int> a;
vector<vector<int>> c;

int dp(int i, int j) {
    if (i == m) return j == 0;
    if (c[i][j] != -1) return c[i][j];

    int sum = 0;
    for (auto x : a) {
        if (i == 0 && x == 0) {
            continue;
        }

        sum += dp(i + 1, (j * 10 + x) % k);
        sum %= MOD;
    }

    return c[i][j] = sum;
}

int main() {
    FAST();

    cin >> n >> m >> k;

    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    c.resize(m, vector<int>(k, -1));

    cout << dp(0, 0) << '\n';
}
