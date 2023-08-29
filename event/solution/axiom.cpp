#include <bits/stdc++.h>

#define FAST() cin.tie(0)->sync_with_stdio(0)

using namespace std;

bool compare(pair<int, int> u, pair<int, int> v) {
    return u.first - u.second < v.first - v.second;
}

int main() {
    FAST();

    int n, a, b;
    cin >> n >> a >> b;

    vector<pair<int, int>> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i].first >> c[i].second;
    }

    sort(c.begin(), c.end(), compare);

    long long sum = 0;
    for (int i = 0; i < a; i++) {
        sum += c[i].first;
    }

    for (int i = a; i < n; i++) {
        sum += c[i].second;
    }

    cout << sum << '\n';
}
