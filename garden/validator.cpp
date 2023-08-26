#include "testlib.h"

using namespace std;
typedef pair<int,int> pii;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int h=inf.readInt(1,4'000,"h");
    inf.readSpace();
    int w=inf.readInt(1,50'000,"w");
    inf.readSpace();
    int n=inf.readInt(1,min(h*w,1'000),"n");
    inf.readEoln();

    set<pii> flower;
    for(int i=1; i<=n; i++){
        int y=inf.readInt(1,h,"y");
        inf.readSpace();
        int x=inf.readInt(1,w,"x");
        inf.readEoln();
        flower.insert({y,x});
    }
    inf.readEof();
    ensuref(flower.size()==n,"꽃의 위치는 전부 달라야합니다.");
}
