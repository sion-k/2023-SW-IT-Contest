#include "testlib.h"

using namespace std;

int n;
vector<int> prime;

inline void readAndCheckAnswer(InStream& in) {
    if (n == 2) {
        in.readLine("NO", "NO");
        in.readEof();
        return;
    }

    in.readLine("YES", "YES");
    vector<int> a = in.readInts(n, 1, n, "a");

    vector<int> f(n + 1);
    for (int i = 0; i < n; i++) {
        f[a[i]]++;
    }

    for (int i = 1; i <= n; i++) {
        if (f[i] != 1) {
            in.quitf(_wa, "%d를 %d번 선물받았습니다.", i, f[i]);
        }
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];

        if (prime[sum]) {
            in.quitf(_wa, "%d번째로 선물받은 수까지의 합이 소수(%d)입니다.", i + 1, sum);
        }
    }
}

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);

    n = inf.readInt();

    int m = n * (n + 1) / 2;
    prime.resize(m + 1, true);
    prime[0] = false;
    prime[1] = false;
    for (int i = 2; i <= m; i++) {
        if (prime[i]) {
            for (int j = i * 2; j <= m; j += i) {
                prime[j] = false;
            }
        }
    }

    readAndCheckAnswer(ans);
    readAndCheckAnswer(ouf);

    quitf(_ok, "OK");
}
