#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    int n = opt<int>(1);

    int new_n[4*n+2];
    vector<int> ka;
    for(int i=1; i<=4*n+1; i++) ka.push_back(i);
    shuffle(ka.begin(), ka.end());

    for(int i=1; i<=4*n+1; i++) new_n[i]=ka[i-1];

    vector<pii> tree;

    int p=2;
    for(int i=1; i<=n; i++){
        tree.push_back({1,p});
        tree.push_back({p,p+1});
        tree.push_back({p+1,p+2});
        tree.push_back({p+1,p+3});
        p+=4;
    }

    cout<<4*n+1<<"\n";
    for(pii u:tree) cout<<new_n[u.first]<<" "<<new_n[u.second]<<"\n";
}