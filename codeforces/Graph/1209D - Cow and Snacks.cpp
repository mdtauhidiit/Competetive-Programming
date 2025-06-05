#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5;
vector<int> adj[N+5];
int vis[N+5];
int comp;

void dfs(int u){
   vis[u]=1;
   for(auto v: adj[u]){
      if(!vis[v]){
         dfs(v);
      }
   }
   comp++;
}

int32_t main(){
   
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   
   int n,k; cin>>n>>k;
   for(int i=0;i<k;i++){
      int u,v; cin>>u>>v;
      adj[u].push_back(v);
      adj[v].push_back(u);
   }
   int ans=0;
   for(int i=1;i<=n;i++){
      if(!vis[i]){
         comp=0;
         dfs(i);
         ans+=(comp-1);
      }
   }
   cout<<max(0LL,k-ans)<<'\n';
   
return 0;
}

