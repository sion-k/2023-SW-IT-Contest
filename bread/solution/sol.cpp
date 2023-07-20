#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a,b,c;
    cin>>a>>b>>c;

    pii k[a];
    for(int i=0; i<a; i++) cin>>k[i].first>>k[i].second;

    auto tp=[](pii x,pii y){
        return x.first-x.second>y.first-y.second;
    };
    sort(k,k+a,tp);

    ll ans=0;
    for(int i=0; i<b; i++) ans+=k[i].first;
    for(int i=b; i<a; i++) ans+=k[i].second;
    cout<<ans;
}