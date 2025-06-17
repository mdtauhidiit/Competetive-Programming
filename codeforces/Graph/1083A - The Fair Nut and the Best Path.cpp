#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=3e5+5;
vector<pair<int,int>> Adj[N];
int w[N],ans[N],dp[N],mx;

//use similar concept as involved in the calculation of diameter


void dfs(int u,int p){
   int mx1=0,mx2=0;
   for(auto x: Adj[u]){
      int v=x.first,wt=x.second;
      if(v!=p) {
         dfs(v,u);
         dp[v]-=wt;
         if(dp[v]>mx1){
            mx2=mx1;mx1=dp[v];
         }
         else if(dp[v]>mx2) mx2=dp[v];
      }
   }
   ans[u]=(mx2+mx1+w[u]);
   dp[u]=mx1+w[u];
   mx=max(mx,ans[u]);
}


void Solve(){
   int n; cin>>n;
   for(int i=1;i<=n;i++) cin>>w[i];
   int m=n-1;
   while(m--){
      int u,v,wt; cin>>u>>v>>wt;
      Adj[u].push_back({v,wt});
      Adj[v].push_back({u,wt});
   }
   mx=0;
   dfs(1,-1);
   cout<<mx<<endl;
}

int32_t main(){
   
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   
   int t=1;
   while(t--){
      Solve();
   }
   
return 0;
}

