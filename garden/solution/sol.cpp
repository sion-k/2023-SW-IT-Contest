#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

bool tp(pii x,pii y){ return x.second<y.second; }
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a,b,c;
    cin>>a>>b>>c;

    vector<pii> k;
    for(int i=0; i<c; i++){
        int y,x;
        cin>>y>>x;
        k.push_back({y,x});
    }
    sort(k.begin(), k.end(),tp);

    int ok=0,ng=1e9,ans=-1;
    while(ok<=ng){
        int mid=(ok+ng)/2;

        bool check=true;
        for(int i=1; i<=a; i++){
            int l=0,r=0;
            for(pii u:k){
                if(abs(i-u.first)>mid) continue;
                else{
                    int n=mid-abs(i-u.first);
                    int tl=max(1,u.second-n),tr=min(b,u.second+n);
                    if(l==0) l=tl,r=tr;
                    else if((l<=tl && tr<=r) || (tl-r>1)) continue;
                    else l=min(l,tl),r=max(r,tr);
                }
            }
            if(l!=1 || r!=b) check=false;
        }
        if(check){
            ans=mid;
            ng=mid-1;
        }else ok=mid+1;
    }
    cout<<ans;
}