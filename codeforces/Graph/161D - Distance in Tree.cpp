#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=50001;
vector<int> Adj[N+5];
int dp[50001][501];
int ans,k;

//dp[u][i] -> # of nodes which are at a distance of exactly i from u

void dfs(int u,int p){
    dp[u][0]=1;
    for(auto v: Adj[u]){
        if(v!=p){
            dfs(v,u);
            for(int i=1;i<=k;i++){
                dp[u][i]+=dp[v][i-1];
            }
        }
    }
    ans+=dp[u][k];
    int tot=0;
    for(auto v: Adj[u]){
        if(v==p) continue;
        for(int i=1;i<=k-1;i++){
            tot+=(dp[v][i-1])*(dp[u][k-i]-dp[v][k-i-1]);
        }
    }
    ans+=tot/2;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; cin>>n>>k;
    int m=n-1;
    while(m--){
        int u,v; cin>>u>>v;
        Adj[u].push_back(v);
        Adj[v].push_back(u);
    }
    dfs(1,0);
    cout<<ans<<'\n';

    return 0;
}
