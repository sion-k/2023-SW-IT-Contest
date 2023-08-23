#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

vector<int> uf(200001);

int find(int x) {
    if (x == uf[x]) return x;
    else return uf[x] = find(uf[x]);
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    uf[x] = y;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    iota(uf.begin(),uf.end(),0);

    int n;
    cin>>n;
    int p[n+1],inv[n+1];
    bool visit[n+1];
    memset(visit,0,sizeof(visit));

    for(int i=1; i<=n; i++) {
        cin>>p[i];
        inv[p[i]]=i;
    }
    for(int i=1; i<=n; i++){
        int v=i;
        while(!visit[v]){
            unite(v,i);
            visit[v]=true;
            v=p[v];
        }
    }

    vector<pii> ans;
    for(int i=1; i<n; i++){
        int w=inv[i],x=inv[i+1],y=i,z=i+1;
        if(find(y)!=find(z)){
            unite(y,z);
            ans.push_back({w,x});
            std::swap(p[w],p[x]);
            std::swap(inv[y],inv[z]);
        }
    }
    cout<<ans.size()<<" "<<ans.size()<<"\n";
    for(pii u:ans) cout<<u.first<<" "<<u.second<<"\n";
}