#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll inf = 1e18, n;
struct node {
    ll s, e, l, r, v;
};

struct seg {
    vector<node> t;
    void init() {
        t.push_back({ 0,inf,-1,-1,0 });
    }
    ll get(ll x, ll p = 0) {
        if (p == -1) return 0;
        ll s = t[p].s, e = t[p].e;
        if (s > x || x > e) return 0;

        ll v = t[p].v;
        v += get(x, t[p].l) + get(x, t[p].r);
        return v;
    }
    void update(ll x, ll l, ll r, ll p) {
        ll s = t[p].s, e = t[p].e;
        if (s > r || e < l) return;
        if (l <= s && e <= r) {
            t[p].v += x;
            return;
        }

        ll mid = (s + e) / 2;
        if (t[p].l == -1) {
            t[p].l = t.size();
            t.push_back({ s,mid,-1,-1,0 });
        }
        if (t[p].r == -1) {
            t[p].r = t.size();
            t.push_back({ mid + 1,e,-1,-1,0 });
        }
        update(x, l, r, t[p].l);
        update(x, l, r, t[p].r);
    }
} seg;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    seg.init();

    cin >> n;
    vector<ll> u;
    for (int i = 0; i < n; i++) {
        ll x; cin >> x;

        ll ok = 0, ng = inf, v = -1, t = inf;
        while (ok <= ng) {
            ll mid = (ok + ng) / 2;
            ll c = seg.get(mid);

            if (c >= x * (n + 1)) {
                v = c;
                t = mid;
                ng = mid - 1;
            } else ok = mid + 1;
        }
        if (v != -1) seg.update(x * (n + 1) + 1, t, inf, 0);
        else seg.update(x * (n + 1) + 1 - seg.get(x), x, inf, 0);
        u.push_back(x);
    }
    ll ans = 0;
    for (ll v : u) ans = max(ans, seg.get(v) % (n + 1));

    cout << ans << '\n';
}
