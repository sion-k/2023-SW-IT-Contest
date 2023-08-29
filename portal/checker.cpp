#include "testlib.h"
#include <bits/stdc++.h>

typedef long long ll;
int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);

    int n=inf.readInt();
    int p[n+1];
    for(int i=1; i<=n; i++) p[i]=inf.readInt();

    int check=0;
    bool visit[n+1];
    memset(visit,0,sizeof(visit));

    for(int i=1; i<=n; i++){
        if(!visit[i]){
            check++;
            int v=i;
            while(!visit[v]){
                visit[v]=true;
                v=p[v];
            }
        }
    }

    ll answer=ouf.readLong(0,(ll)1e18);
    if(answer!=check){
        quitf(_wa,"The answer is wrong: expected = %d, found = %lld",check,answer);
    }else{
        int s=ouf.readInt(0,(int)answer);
        ll sum=0;

        for(int i=0; i<s; i++){
            int a=ouf.readInt(1,n);
            int b=ouf.readInt(1,n);
            if(a==b){
                quitf(_pe,"They must not be equal");
            }
            sum+=(p[a]-p[b])*(p[a]-p[b]);
            std::swap(p[a],p[b]);
        }

        memset(visit,0,sizeof(visit));
        check=0;

        for(int i=1; i<=n; i++){
            if(!visit[i]){
                check++;
                int v=i;
                while(!visit[v]){
                    visit[v]=true;
                    v=p[v];
                }
            }
        }

        if(check>1){
            quitf(_wa,"There are %d permutation cycles in the array",check);
        }
        else if(sum!=answer){
            quitf(_wa,"Your answer is not same as sum: sum = %lld, answer = %lld",sum,answer);
        }
        else{
            quitf(_ok,"Answer is correct");
        }
    }
}