#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e5;
vector<vector<int>> Adj;
vector<int> vis,dp,cycle,par;
vector<int> path;
int starting,ending;

void ExtractCycle(int u,int p){
   vis[u]=1; par[u]=p;
   for(auto v: Adj[u]){
      if(!vis[v]){
         ExtractCycle(v,u);
      }
      else if(v!=p){
         ending=v,starting=u;
         return ;
      }
   }
}

void GetCycle(int starting,int ending){
   while(ending!=starting){
      path.push_back(ending);
      cycle[ending]=1;
      ending=par[ending];
   }
   path.push_back(starting);
   cycle[starting]=1;
}

void dfs(int u,int p){
   dp[u]=1;
   for(auto v: Adj[u]){
      if(!cycle[v] && v!=p){
         dfs(v,u);
         dp[u]+=dp[v];
      }
   }
}

void PreProcess(int n){
   Adj.resize(n+1);
   vis.resize(n+1,0);
   par.resize(n+1,-1);
   dp.resize(n+1,0);
   cycle.resize(n+1,0);
}

void Clear(){
   Adj.clear();
   vis.clear();
   dp.clear();
   cycle.clear();
   par.clear();
   path.clear();
}


int32_t main(){
   
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   
   int t; cin>>t;
   while(t--){
      int n; cin>>n;
      PreProcess(n);
      for(int i=1;i<=n;i++){
         int u,v; cin>>u>>v;
         Adj[u].push_back(v);
         Adj[v].push_back(u);
      }
      ExtractCycle(1,0);
      GetCycle(starting,ending);
      int ans=n*(n-1);
      for(auto p: path){
         dfs(p,-1);
         int x=dp[p];
         ans-=((x)*(x-1))/2;
      }
      cout<<ans<<'\n';
      Clear();
   }   
   return 0;
}
 
