#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, a, b;
    cin >> n >> a >> b;

    pii k[n];
    for (int i = 0; i < n; i++) {
        cin >> k[i].first >> k[i].second;
    }

    auto compare = [](pii x, pii y) {
        return x.first - x.second < y.first - y.second;
        };
    sort(k, k + n, compare);

    ll ans = 0;
    for (int i = 0; i < a; i++) ans += k[i].first;
    for (int i = a; i < n; i++) ans += k[i].second;

    cout << ans << '\n';
}
