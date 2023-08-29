#include "testlib.h"

using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int n = atoi(argv[2]);
    int m = atoi(argv[3]);
    int v = atoi(argv[4]);

    cout<<n<<" "<<m<<"\n";

    vector<int> p;
    for(int i=1; i<=n*m; i++) p.push_back(i);
    shuffle(p.begin(),p.end());

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<p[i*m+j];
            if(j<m-1) cout<<" ";
        }
        cout<<"\n";
    }
    if(v==-1) cout<<rnd.next(1,min(100'000,n*m))<<"\n";
    else cout<<v<<"\n";
}
