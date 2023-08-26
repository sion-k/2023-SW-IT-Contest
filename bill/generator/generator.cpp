#include "testlib.h"
 
using namespace std;
 
const int N_MIN = 1, N_MAX = 100;
const vector<int> ALLOWED_VALUES = {136, 142, 148, 154};
 
int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
 
    int n, m;
    if (argc >= 4) {
        n = atoi(argv[2]);
        if (n == -1) n = rnd.next(N_MIN, N_MAX);
        m = atoi(argv[3]);
    } else {
        n = rnd.next(N_MIN, N_MAX);
        m = -1;
    }
    
    cout << n << '\n';
 
    if (m == -1) {
        for (int i = 0; i < n; i++) {
            cout << rnd.any(ALLOWED_VALUES.begin(), ALLOWED_VALUES.end()) << ' ' << 68 << '\n';
        }
    } else {
        for (int i = 0; i < n; i++) {
            cout << m << ' ' << 68 << '\n';
        }
    }
}