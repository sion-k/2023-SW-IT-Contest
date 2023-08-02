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

    if (n == 1) cout << 1;
    else if (n == 2) cout << -1;
    else {
        cout << "1 3 2 ";
        for (int i = 4; i <= n; i++) cout << i << " ";
    }
}