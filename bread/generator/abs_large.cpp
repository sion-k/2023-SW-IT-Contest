#include "testlib.h"

using namespace std;

const int N = 1'000'000'000;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int g = atoi(argv[1]);
    int rd = atoi(argv[2]); //rd값이 0이면 항상 x<y

    int r = rnd.next(2, g);
    int p = rnd.next(1, r - 1), q = r - p;

    cout << r << "\n" << p << " " << q << "\n";

    for (int i = 0; i < g; i++) {

        int s = rnd.next(N / 4, N - 1);
        int u = rnd.next(0, 1);
        int x, y;
        x = rnd.next(1, N - s), y = s + x;
        if (rd && u) swap(x, y);

        cout << x << " " << y << "\n";
    }
}
