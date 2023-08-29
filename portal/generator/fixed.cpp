#include "testlib.h"

using namespace std;

const int N_MIN = 1, N_MAX = 200'000;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);


    int n = atoi(argv[1]);
    int p[n];
    for(int i=0; i<n; i++) p[i]=i+1;
    shuffle(p,p+n);

    cout<<n<<'\n';
    for(int i=0; i<n; i++) {
        cout<<p[i];
        if(i<n-1) cout<<' ';
    }
    cout<<'\n';
}
