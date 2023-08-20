#include <bits/stdc++.h>

#define FAST() cin.tie(0)->sync_with_stdio(0)
#define OPEN(t) freopen("data.txt", (t), (t == "r" ? stdin : stdout))
#define ALL(x) (x).begin(), (x).end()
#define SIZE(x) (int)((x).size())

#define deb(x) cout << #x << " : " << (x) << "\n"
#define deb_pair(x, y) cout << "(" << #x << ", " << #y << ") : (" << (x) << ", " << (y) << ")\n"
#define deb_triplet(x, y, z) cout << "(" << #x << ", " << #y << ", " << #z << ") : (" << (x) << ", " << (y) << ", " << (z) << ")\n"
#define deb_tuple(s) \
    cout << "["; \
    for (int __i = 0; __i < SIZE(s); __i++) { \
        cout << s[__i]; \
        if (__i != SIZE(s) - 1) cout << ", "; \
    } \
    cout << "]\n";

using namespace std;

int n, s;
vector<int> prime, used, ans;

void btk() {
    if (SIZE(ans) == n) {
        cout << "YES" << '\n';
        for (int i = 0; i < n; i++) {
            cout << ans[i] << " \n"[i == n - 1];
        }
        exit(0);
    }

    for (int i = 1; i <= n; i++) {
        if (used[i] || prime[s + i]) continue;

        used[i] = true;
        ans.push_back(i);
        s += i;
        btk();
        s -= i;
        ans.pop_back();
        used[i] = false;
    }
}

int main() {
    FAST();

    cin >> n;

    int m = n * (n + 1) / 2;
    prime.resize(m + 1, true);
    prime[0] = false;
    prime[1] = false;
    for (int i = 2; i <= m; i++) {
        if (prime[i]) {
            for (int j = i * 2; j <= m; j += i) {
                prime[j] = false;
            }
        }
    }

    used.resize(n + 1, false);
    btk();

    cout << "NO" << '\n';
}
