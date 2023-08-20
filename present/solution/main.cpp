#include <bits/stdc++.h>

#define FAST() cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main() {
    FAST();

    int n;
    cin >> n;

    if (n == 2) {
        cout << "NO" << '\n';
    } else {
        cout << "YES" << '\n';
        vector<int> a = { 1, 3, 2 };
        for (int i = 4; i <= n; i++) {
            a.push_back(i);
        }

        for (int i = 0; i < n; i++) {
            cout << a[i] << " \n"[i == n - 1];
        }
    }
}
