#include "testlib.h"

using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int h=atoi(argv[2]);
    int w=atoi(argv[3]);
    int n=atoi(argv[4]);

    cout<<h<<" "<<w<<" "<<n<<"\n";

    vector<int> flower=rnd.distinct(n,0,h*w-1);
    shuffle(flower.begin(), flower.end());
    for(int u:flower) cout<<u/w+1<<" "<<u%w+1<<"\n";
}
