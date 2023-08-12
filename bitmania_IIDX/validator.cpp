#include "testlib.h"

using namespace std;

const int K = 32, N=100'000;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int k=inf.readInt(1,K, "k");
    inf.readSpace();
    int n=inf.readInt(1,N,"n");
    inf.readEoln();

    for(int i=1; i<=n; i++){
        int a=inf.readInt(1,(1<<k)-1,"a");
        inf.readSpace();
    }
    inf.readEoln();
    inf.readEof();
}
