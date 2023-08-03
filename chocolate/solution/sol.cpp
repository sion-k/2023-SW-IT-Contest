#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int dydx[4][2]{{1,0},{0,1},{-1,0},{0,-1}};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int choco[n][m];
    pii rc[n * m + 1];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> choco[i][j];
            rc[choco[i][j]] = {i, j};
        }
    }

    bool eat[n][m];
    memset(eat, 0, sizeof(eat));
    priority_queue<int> pq;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
                if (!eat[i][j]) {
                    eat[i][j] = true;
                    pq.push(choco[i][j]);
                }
            }
        }
    }

    int k;
    cin >> k;
    for (int t = 0; t < k; t++) {
        int x = pq.top();
        pq.pop();
        cout << rc[x].first + 1 << " " << rc[x].second + 1 << "\n";
        for (auto u: dydx) {
            int nr = rc[x].first + u[0], nc = rc[x].second + u[1];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && !eat[nr][nc]) {
                eat[nr][nc] = true;
                pq.push(choco[nr][nc]);
            }
        }
    }
}