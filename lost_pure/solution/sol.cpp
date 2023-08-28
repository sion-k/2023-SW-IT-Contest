#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int N, u, v;

typedef pair<int, int> box;

vector<int> load[101010], dp[101010];

#define first from;
#define second target;

void dfs (int node, int prev = 0) {
    vector<int> two, one;
    bool ends = true;

    for(int next : load[node]) if (next != prev) {
            dfs(next, node);

            if(dp[next].size() == 1) {
                one.push_back(next);
            } else {
                two.push_back(next);
            }
            ends = false;
        }

    if(ends) return;

    //case work

    if(two.size() == 1) {
        if (!one.empty()) {
            int twoo = two[0];

            int another = one[one.size()-1];
            one.pop_back();

            cout << dp[another][0] << ' ' << dp[twoo][1] << '\n';

            dp[twoo].pop_back();
            two.clear();
            one.push_back(twoo);

        } else {
            for (int i : dp[two[0]]) dp[node].push_back(i);
            return;
        }
    }

    // Now no two 1 case

    for(int i = 1;i<two.size();i++) {
        cout << dp[two[i-1]][0] << ' ' << dp[two[i]][1] << '\n';
    }

    if(!two.empty()) {
        int siz = two.size();
        dp[two[0]][0] = dp[two[0]][1];

        dp[two[0]].pop_back();
        dp[two[siz-1]].pop_back();

        one.push_back(two[0]);
        one.push_back(two[siz-1]);
    }

    int up = one.size() % 2 == 0 ? 2 : 1;

    for(int i=0;i<up;i++) {
        dp[node].push_back(dp[one[one.size()-1]][0]);
        one.pop_back();
    }

    for(int i=0;i<one.size();i+=2) {
        cout << dp[one[i]][0] << ' ' << dp[one[i+1]][0] << '\n';
    }

}

int main () {
    cin >> N;

    for(int i=1;i<N;i++) {
        cin >> u >> v;

        load[u].push_back(v);
        load[v].push_back(u);
    }

    int start, ano = 0;

    for(int i = 1;i<=N;i++) {
        if(load[i].size() == 1) {
            dp[i].push_back(i);
            ano++;
            start = i;

        }
    }

    ano = ano / 2 + (ano &1);

    cout << ano << '\n';
    dp[start].clear();

    dfs(start);

    for(int i=0;i<dp[start].size();i++) {
        cout << start << ' ' << dp[start][i] << '\n';
    }
    return 0;
}