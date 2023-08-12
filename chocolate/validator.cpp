#include "testlib.h"

using namespace std;

const int N= 1'000;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int n = inf.readInt(1, N, "n");
    inf.readSpace();
    int m=inf.readInt(1,N,"m");
    inf.readEof();

    bool check[n*m+1];
    memset(check,0,sizeof(check));
    for(int i=1; i<=n; i++){
        for(int j=0; j<=m; j++){
            int a=inf.readInt(1,n*m,"a");
            inf.readSpace();
            check[a]=true;
        }
        inf.readEoln();
    }

    bool f=true;
    for(int i=1; i<=n*m; i++) f&=check[i];
    ensuref(f,"1에서 N*M까지의 수가 전부 한번씩 사용되어야합니다");
    inf.readEof();
}
