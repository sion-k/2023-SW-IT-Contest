#include "testlib.h"

using namespace std;

const int N=50'000, M=100,V = 500;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int n = inf.readInt(1, N, "n");
    inf.readSpace();
    int m=inf.readInt(1,M,"m");
    inf.readSpace();
    int k=inf.readInt(1,n,"k");
    inf.readEoln();

    for(int i=1; i<=m; i++){
        int a=inf.readInt(1,V,"a");
        inf.readSpace();
        int b=inf.readInt(1,V,"b");
        inf.readEoln();
    }

    for(int i=1; i<=n; i++){
        int a=inf.readInt(1,V,"a");
        inf.readSpace();
        int b=inf.readInt(1,V,"b");
        inf.readEoln();
    }
    inf.readEof();
}
