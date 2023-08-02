#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    int sat[501][501], knapsack[501][501];
    memset(sat, 0, sizeof(sat));
    for (int i = 0; i <= 500; i++) {
        for (int j = 0; j <= 500; j++) knapsack[i][j] = 1e9;
    }

    knapsack[0][0] = 0;
    for (int i = 1; i <= m; i++) {
        int p, q;
        cin >> p >> q;
        for (int x = 500; x >= 0; x--) {
            for (int y = 500; y >= 0; y--) {
                if (knapsack[x][y] != -1)
                    knapsack[min(500, x + p)][min(500, y + q)] = min(knapsack[min(500, x + p)][min(500, y + q)],
                                                                     knapsack[x][y] + 1);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        int p, q;
        cin >> p >> q;
        sat[p][q]++;
    }

    for (int i = 1; i <= 500; i++) {
        for (int j = 1; j <= 500; j++) sat[i][j] += sat[i][j - 1];
    }

    for (int i = 0; i <= 500; i++) {
        for (int j = 1; j <= 500; j++) sat[j][i] += sat[j - 1][i];
    }

    int ans = 1e9;
    for (int i = 0; i <= 500; i++) {
        for (int j = 0; j <= 500; j++) {
            if (sat[i][j] >= k) ans = min(ans, knapsack[i][j]);
        }
    }
    if (ans == 1e9) cout << -1;
    else cout << ans;
}