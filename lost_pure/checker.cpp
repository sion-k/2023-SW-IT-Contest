#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int leaf=0,t=0;
vector<int> adj[100'001];
bool visit[100'001],bridge=false;

int tin[100'001],low[100'001];

void dfs(int x){
    visit[x]=true;
    bool f=true;
    for(int u:adj[x]){
        if(!visit[u]){
            f=false;
            dfs(u);
        }
    }
    leaf+=f;
}

void find_bridge(int x,int p=-1){
    visit[x]=true;
    tin[x]=low[x]=t++;
    for(int i=0; i<adj[x].size(); i++){
        int u=adj[x][i];
        if(u==p) continue;
        if(visit[u]){
            low[x]=min(low[x],tin[u]);
        }else{
            find_bridge(u,x);
            low[x]=min(low[x],low[u]);
            if(low[u]>tin[x] && (adj[u].size()<=2 || adj[x].size()<=2)) bridge=true;
        }
    }
}


int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);

    int n=inf.readInt();
    set<pii> st;

    for(int i=1; i<n; i++){
        int x=inf.readInt();
        int y=inf.readInt();
        st.insert({x,y});
        st.insert({y,x});
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int s=-1;
    for(int i=1; i<=n; i++){
        if(adj[i].size()>1){
            s=i;
            break;
        }
    }
    dfs(s);

    int a=ouf.readInt(0,n,"a");
    if(a!=(leaf+1)/2){
        quitf(_wa,"The answer is wrong: expected = %d, found = %d",(leaf+1)/2,a);
    }else{
        for(int i=0; i<a; i++){
            int x=ouf.readInt(1,n,"x");
            int y=ouf.readInt(1,n,"y");
            if(x==y){
                quitf(_wa,"x and y should be different");
            }
            if(st.count({x,y})){
                quitf(_wa,"This node is already used");
            }
            st.insert({x,y});
            st.insert({y,x});
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        memset(visit,0,sizeof(visit));
        find_bridge(s);
        if(bridge){
            quitf(_wa,"Wrong Answer");
        }else{
            quitf(_ok,"Answer is true");
        }
    }
}