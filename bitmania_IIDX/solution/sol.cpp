#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k, n;
    cin >> k >> n;

    vector<ll> bit(k);

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        for (int j = 0; j < k; j++) {
            if (x & (1 << j)) bit[j]++;
        }
    }

    ll ans = 0, sum = 0;
    for (int i = 0; i < k; i++) {
        if (bit[i] > n / 2) {
            sum += bit[i] * (1 << i);
        } else {
            ans |= (1 << i);
            sum += (n - bit[i]) * (1 << i);
        }
    }
    cout << ans << "\n" << sum;
}