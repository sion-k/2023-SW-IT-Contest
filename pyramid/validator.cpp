#include "testlib.h"

using namespace std;

const int N=200'000, M=1'000'000'000;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int n = inf.readInt(1,N, "n");
    inf.readEoln();

    for(int i=1; i<=n; i++){
        int a=inf.readInt(1,M,"a");
        inf.readSpace();
    }
    inf.readEoln();
    inf.readEof();
}
