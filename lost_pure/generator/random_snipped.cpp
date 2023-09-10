#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    int n = opt<int>(1);

    int new_n[4+4*n+1];
    vector<int> ka;
    for(int i=1; i<=4+4*n; i++) ka.push_back(i);
    shuffle(ka.begin(), ka.end());

    for(int i=1; i<=4+4*n; i++) new_n[i]=ka[i-1];

    vector<int> use;
    vector<pii> tree;

    tree.push_back({1,2});
    tree.push_back({1,3});
    tree.push_back({1,4});
    use.push_back(1);
    use.push_back(2);
    use.push_back(3);
    use.push_back(4);

    int p=5;
    for(int i=1; i<=n; i++){
        int x=rnd.next(0,(int)use.size()-1);
        int v=use[x];
        tree.push_back({v,p});
        use.push_back(p);
        tree.push_back({p,p+1});
        use.push_back(p+1);
        tree.push_back({p+1,p+2});
        use.push_back(p+2);
        tree.push_back({p+1,p+3});
        use.push_back(p+3);
        p+=4;
    }

    cout<<4+4*n<<"\n";
    for(pii u:tree) cout<<new_n[u.first]<<" "<<new_n[u.second]<<"\n";
}