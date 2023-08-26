#include <iostream>
 
using namespace std;
 
int main() {
    int N; cin >> N;
    int ans = 0;
 
    while (N--) {
        int w, h; cin >> w >> h;
        if (w == 136) ans += 1000;
        else if (w == 142) ans += 5000;
        else if (w == 148) ans += 10000;
        else ans += 50000;
    }
 
    cout << ans;
}