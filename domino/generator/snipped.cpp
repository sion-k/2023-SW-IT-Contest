#include "testlib.h"

using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int nx = opt<int>(1);
    int v =opt<int>(2);
    int n;
    if(v==0) n=nx;
    else n=rnd.next(10000,nx);
    int t=rnd.next((int)sqrt(n),n/4);

    int k[n];
    k[0]=1;
    for(int i=1; i<=t; i++) k[i]=rnd.next(k[i-1]+1,k[i-1]+1000);
    for(int i=t+1; i<2*t; i++) k[i]=rnd.next(1,10);
    k[2*t]=rnd.next(k[t]+1,k[t]+1000);
    for(int i=2*t+1; i<=3*t; i++) k[i]=rnd.next(k[i-1]+1,k[i-1]+1000);
    for(int i=3*t+1; i<n; i++) k[i]=i-3*t;

    cout<<n<<"\n";
    for(int i=0; i<n; i++){
        cout<<k[i];
        if(i<n-1) cout<<" ";
    }
    cout<<"\n";
}
