#include "testlib.h"

using namespace std;

const int N_MIN = 3, N_MAX = 100'000;
vector<int> adj[100'001];
bool visit[100'001];

void dfs(int x){
    visit[x]=true;
    for(int u:adj[x]){
        if(!visit[u]) dfs(u);
    }
}

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int n = inf.readInt(N_MIN, N_MAX, "n");
    inf.readEoln();
    for(int i=1; i<n; i++){
        int x=inf.readInt(1,n,"x");
        inf.readSpace();
        int y=inf.readInt(1,n,"y");
        ensuref(x!=y,"x and y should be different");
        inf.readEoln();
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    inf.readEof();
    dfs(1);
    bool f=true;
    for(int i=1; i<=n; i++) f&=visit[i];
    ensuref(f,"Given graph should be a tree");
}
