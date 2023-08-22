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
    uf[x] = y;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    iota(uf.begin(),uf.end(),0);

    int n;
    cin>>n;
    int cycle[n+1],inv[n+1];

    bool visit[n+1];
    memset(visit,0,sizeof(visit));

    for(int i=1; i<=n; i++) {
        cin>>cycle[i];
        inv[cycle[i]]=i;
    }
    for(int i=1; i<=n; i++){
        int p=i;
        while(!visit[p]){
            visit[p]=true;
            int nxt=cycle[p];
            unite(p,nxt);
            p=nxt;
        }
    }

    vector<pii> ans;
    for(int i=1; i<=n; i++){
        if(cycle[i]>1 && find(cycle[i])!=find(cycle[i]-1)){
            ans.push_back({i,inv[cycle[i]-1]});
            unite(cycle[i],cycle[i]-1);
            swap(cycle[i],cycle[inv[cycle[i]-1]]);
        }
        if(cycle[i]<n && find(cycle[i])!=find(cycle[i]+1)){
            ans.push_back({i,inv[cycle[i]+1]});
            unite(cycle[i],cycle[i]+1);
            swap(cycle[i],cycle[inv[cycle[i]+1]]);
        }
    }
    cout<<ans.size()<<" "<<ans.size()<<"\n";
    for(pii u:ans) cout<<u.first<<" "<<u.second<<"\n";
}