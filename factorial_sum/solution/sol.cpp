#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod=1e9+7;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll F[1000001];
    F[0]=1,F[1]=1;
    for(int i=2; i<=1000000; i++) F[i]=(i*F[i-1]+1)%mod;
    for(int i=1; i<=1000000; i++) F[i]=(F[i-1]+F[i])%mod;

    int a,b;
    cin>>a>>b;
    cout<<F[b]-F[a-1];
}