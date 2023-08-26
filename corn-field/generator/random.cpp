#include "testlib.h"

using namespace std;

const int N_MIN = 1, N_MAX = 1'000;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int l=atoi(argv[2]);
    int n = rnd.next(N_MIN, l);
    int m = rnd.next(N_MIN,l);

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
    cout<<rnd.next(N_MIN,n*m)<<"\n";
}
