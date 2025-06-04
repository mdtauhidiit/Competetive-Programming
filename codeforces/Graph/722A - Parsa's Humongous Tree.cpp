#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e5;

vector<vector<int>> Adj,dp;
vector<int> l,r;

void dfs(int u,int p){
   for(auto v: Adj[u]){
      if(v!=p){
         dfs(v,u);
         dp[u][0]+=max(abs(l[u]-l[v])+dp[v][0],abs(l[u]-r[v])+dp[v][1]);
         dp[u][1]+=max(abs(r[u]-l[v])+dp[v][0],abs(r[u]-r[v])+dp[v][1]);
      }
   }
}

void Initialize(int n){
   Adj.resize(n+1);
   dp.resize(n+1,vector<int> (2));
   l.resize(n+1);
   r.resize(n+1);
}

void Clear(){
   Adj.clear();
   l.clear();
   r.clear();
   dp.clear();
}

int32_t main(){
   
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   
   int t; cin>>t;
   while(t--){
      int n; cin>>n;
      Initialize(n);
      for(int i=1;i<=n;i++) cin>>l[i]>>r[i];
      for(int i=1;i<n;i++){
         int u,v; cin>>u>>v;
         Adj[u].push_back(v);
         Adj[v].push_back(u);
      }
      for(int i=1;i<=n;i++) dp[i][0]=dp[i][1]=0;
      dfs(1,-1);
      cout<<max(dp[1][0],dp[1][1])<<'\n';
      Clear();
   }
   
   return 0;
}


 
