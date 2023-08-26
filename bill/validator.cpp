#include "testlib.h"
 
using namespace std;
 
const int N_MIN = 1, N_MAX = 100;
const set<int> ALLOWED_VALUES = {136, 142, 148, 154};
 
int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
 
    int n = inf.readInt(N_MIN, N_MAX, "n");
    inf.readEoln();
 
    for (int i = 0; i < n; i++) {
        int m = inf.readInt(136, 154, "m");
        inf.readSpace();
        int k = inf.readInt(68, 68, "k");
        inf.readEoln();
        
        ensuref(ALLOWED_VALUES.find(m)!=ALLOWED_VALUES.end(), "규격 외의 크기를 입력했습니다.");
    }
 
    inf.readEof();
}