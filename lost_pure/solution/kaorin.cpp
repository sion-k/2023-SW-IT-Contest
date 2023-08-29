#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

vector<int> adj[100001];
bool vi[100001];
vector<pii> ans;
int s=-1;

vector<int> rec(int x){
    vi[x]=true;
    vector<vector<int>> k;
    int v=0;

    for(int u:adj[x]){
        if(!vi[u]){
            auto n=rec(u);
            v+=n.size();
            k.push_back(n);
        }
    }
    if(v==0){
        vector<int> c;
        c.push_back(x);
        return c;
    }
    auto tp=[](vector<int> &x,vector<int> &y){
        return x.size()>y.size();
    };
    sort(k.begin(),k.end(),tp);

    int e=v-k[0].size();
    while(v>2){
        if(k[0].size()<e){
            auto t1=k.back();
            k.pop_back();
            auto t2=k.back();
            k.pop_back();

            ans.push_back({t1.back(),t2.back()});
            t1.pop_back(),t2.pop_back();
            if(!t1.empty()) k.push_back(t1);
            if(!t2.empty()) k.push_back(t2);
            e-=2;
        }else{
            auto t1=k.back();
            k.pop_back();
            ans.push_back({t1.back(),k[0].back()});
            t1.pop_back(),k[0].pop_back();
            if(!t1.empty()) k.push_back(t1);
            e--;
        }
        v-=2;
    }
    vector<int> n;
    for(auto u:k){
        for(int r:u) n.push_back(r);
    }
    if(x==s){
        if(n.size()==2) ans.push_back({n[0],n[1]});
        else{
            bool ch=false;
            int r=-1;
            for(int u:adj[x]){
                if(u==n[0]) ch=true;
                else r=u;
            }
            if(ch) ans.push_back({n[0],r});
            else ans.push_back({n[0],x});
        }
    }
    return n;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a;
    cin>>a;
    for(int i=1; i<a; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for(int i=1; i<=a; i++){
        if(adj[i].size()>1){
            s=i;
            break;
        }
    }
    rec(s);
    cout<<ans.size()<<"\n";
    for(pii u:ans) cout<<u.first<<" "<<u.second<<"\n";
}