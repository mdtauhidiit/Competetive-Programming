#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5+5;
vector<pair<int,int>> Adj[N];
int dp[N];

void dfs(int u,int p=0){
   for(auto x: Adj[u]){
      int v=x.first,w=x.second;
      if(v!=p){
         dfs(v,u);
         dp[u]=max(dp[u],dp[v]+w);
      }
   }
}

int32_t main(){
   
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   
   int n; cin>>n;
   int m=n-1,sum=0;
   while(m--){
      int u,v,w; cin>>u>>v>>w;
      Adj[u].push_back({v,w});
      Adj[v].push_back({u,w});
      sum+=w;
   }
   dfs(1);
   cout<<2*sum-dp[1]<<'\n';
   
   
   
return 0;
}

