#include "testlib.h"

using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int hv=atoi(argv[2]);
    int wv=atoi(argv[3]);
    int nv= atoi(argv[4]);

    int h=rnd.next(1,hv);
    int w=rnd.next(1,wv);
    int n=rnd.next(1,min(hv*wv,nv));

    cout<<h<<" "<<w<<" "<<n<<"\n";

    vector<int> flower=rnd.distinct(n,0,h*w-1);
    shuffle(flower.begin(), flower.end());
    for(int u:flower) cout<<u/w+1<<" "<<u%w+1<<"\n";
}
