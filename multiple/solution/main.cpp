#include <iostream>
#include <algorithm>
#include <vector>

#define MOD 1000000007

using namespace std;
using ll = long long;

int N, M, K;
string s;
vector<int> vc;

ll solve() {
    ll dist[1000][101];
    for (int i = 0; i < 1000; i++) {
        fill(dist[i], dist[i] + 101, 0LL);
    }

    for (int n : vc) {
        if (n == 0) continue;
        int cur = n % K;
        ++dist[cur][1];
    }

    for (int j = 2; j < M + 1; j++) {
        for (int i = 0; i < K; i++) {
            for (int n : vc) {
                int cur = (i * 10 + n) % K;
                dist[cur][j] += dist[i][j - 1];
                dist[cur][j] %= MOD;
            }
        }
    }

    return dist[0][M];
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) {
        int n; cin >> n;
        vc.push_back(n);
    }

    cout << solve();

    return 0;
}
