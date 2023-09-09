#include <bits/stdc++.h>

#define FAST() cin.tie(0)->sync_with_stdio(0)

using namespace std;

// longest perfect subsequence
int lps(int n, vector<int>& a, int start) {
    long long sum = a[start], cnt = 1;

    for (int i = start + 1; i < n; i++) {
        if (sum >= a[i]) {
            sum += a[i];
            cnt++;
        }
    }

    return cnt;
}

int main() {
    FAST();

    int n;
    cin >> n;

    vector<int> a(n);
    for (auto& x : a) {
        cin >> x;
    }

    int max = 0;
    for (int i = 0; i < n; i++) {
        max = ::max(max, lps(n, a, i));

        if (max == n - i) {
            break;
        }
    }

    cout << max << '\n';
}
