#include "testlib.h"

using namespace std;

int a, b;

inline void readAndCheckAnswer(InStream& in) {
    if (b + 1 <= a && a <= 2 * b) {
        in.readLine("YES", "YES");

        int k = in.readInt(1, b, "k");
        in.readEoln();

        int patty = a, cheese = b;

        vector<string> a(k);
        for (int i = 0; i < k; i++) {
            a[i] = in.readLine(format("[ab]{1,%d}", patty + cheese), format("a[%d]", i + 1));

            for (int j = 0; j < (int)a[i].length(); j++) {
                if (j % 2 == 0 && a[i][j] != 'a' || j % 2 == 1 && a[i][j] != 'b') {
                    in.quitf(_wa, "패티와 치즈가 번갈아 나와야 합니다.");
                }

                if (j % 2 == 0) {
                    patty--;
                } else {
                    cheese--;
                }

                if (patty < 0 || cheese < 0) {
                    in.quitf(_wa, "패티나 치즈가 부족합니다.");
                }
            }
        }

        if (patty != 0 || cheese != 0) {
            in.quitf(_wa, "패티나 치즈가 남았습니다.");
        }
    } else {
        in.readLine("NO", "NO");
    }
}

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);

    a = inf.readInt();
    b = inf.readInt();

    readAndCheckAnswer(ans);
    readAndCheckAnswer(ouf);

    quitf(_ok, "a=%d, b=%d", a, b);
}
