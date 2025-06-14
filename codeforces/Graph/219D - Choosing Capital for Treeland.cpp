#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e5+5;
vector<vector<int>> Adj[N];
int numUp[N],numDown[N];
int dp[N],totalUpwards,n;

void dfs(int u,int p){
   for(auto x: Adj[u]){
      int v=x[0],w=x[1];
      if(v==p) continue;
      if(w==0) numDown[v]=numDown[u]+1;
      else numDown[v]=numDown[u];
      if(w==1) numUp[v]=numUp[u]+1;
      else numUp[v]=numUp[u];
      dfs(v,u);
      totalUpwards+=w;
   }
}

int32_t main(){
   
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   
   cin>>n;
   int m=n-1;
   while(m--){
      int u,v; cin>>u>>v;
      Adj[u].push_back({v,0});
      Adj[v].push_back({u,1});
   }
   dfs(1,0);
   int ans=1e9;
   for(int i=1;i<=n;i++) {
      dp[i]=numDown[i]+totalUpwards-numUp[i];
      ans=min(ans,dp[i]);
   }
   cout<<ans<<endl;
   for(int i=1;i<=n;i++){
      if(dp[i]==ans) cout<<i<<" ";
   }
   
   
return 0;
}

