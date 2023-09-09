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

class Disjoint_set {
public:
    int n;
    vector<int> parent, rank, size;

    Disjoint_set() {}

    Disjoint_set(int n) : n(n), parent(n), rank(n), size(n, 1) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    void merge(int u, int v) {
        u = find(u); v = find(v);
        if (u == v) return;
        if (rank[u] > rank[v]) swap(u, v);
        parent[u] = v;
        size[v] += size[u];
        if (rank[u] == rank[v]) rank[v]++;
    }

    int find(int u) {
        if (u == parent[u]) return u;
        return parent[u] = find(parent[u]);
    }
};

int n;
vector<int> a, v, p;
Disjoint_set d;

void dfs(int here, int prev) {
    v[here] = true;
    d.merge(here, prev);

    int there = a[here];
    if (!v[there]) {
        dfs(there, here);
    }
}

int main() {
    FAST();

    cin >> n;

    a.resize(n + 1);
    v.resize(n + 1);
    p.resize(n + 1);
    d = Disjoint_set(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        p[a[i]] = i;
    }

    int c = 0, m = 0;
    for (int i = 1; i <= n; i++) if (!v[i]) {
        dfs(i, i);
        c++, m++;
    }

    cout << c - 1 << ' ' << m - 1 << '\n';
    for (int i = 1; i <= n - 1; i++) {
        if (d.find(i) != d.find(i + 1)) {
            cout << p[i] << ' ' << p[i + 1] << '\n';
            swap(p[i], p[i + 1]);
            d.merge(i, i + 1);
        }
    }
}
