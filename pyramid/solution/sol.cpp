#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    ll k[n], ka[n], ans[n], now = 0;
    for (int i = 0; i < n; i++) {
        cin >> k[i];
        ka[i] = k[i];
    }
    for (int i = n - 2; i >= 0; i--) {
        ka[i] = max(ka[i], ka[i + 1] + 1);
        now += ka[i] - k[i];
    }

    ans[0] = now;
    now -= ka[1] - k[1] + ka[0] - k[0];
    ka[0] = k[0];
    ka[1] = max(ka[1], ka[0] + 1);
    now += ka[1] - k[1] + ka[0] - k[0];
    ans[1] = now;

    for (int i = 2; i < n; i++) {
        now -= ka[i] - k[i] + ka[i - 1] - k[i - 1];
        ka[i - 1] = max(k[i - 1], ka[i - 2] + 1);
        ka[i] = max(ka[i], ka[i - 1] + 1);
        now += ka[i] - k[i] + ka[i - 1] - k[i - 1];
        ans[i] = now;
    }

    for (ll u: ans) cout << u << "\n";
}