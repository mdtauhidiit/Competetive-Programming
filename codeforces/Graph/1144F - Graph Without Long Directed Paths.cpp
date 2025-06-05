#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=5e5;
const int mod=1e9+7;
vector<int> Adj[N+5];
int col[N+5];

bool Bipartite(int u,int x){
   col[u]=x;
   for(auto v: Adj[u]){
      if(col[v]==0){
         if(!Bipartite(v,3-x)) return false;
      }
      else if(col[v]==col[u]) return false;
   }
   return true;
}

int32_t main(){
   
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   
   int n,m; cin>>n>>m;
   vector<vector<int>> edges;
   while(m--){
      int u,v; cin>>u>>v;
      edges.push_back({u,v});
      Adj[u].push_back(v);
      Adj[v].push_back(u);
   }
   if(!Bipartite(1,1)) cout<<"NO\n";
   else{
      cout<<"YES\n";
      for(auto e: edges){
         int u=e[0],v=e[1];
         if(col[u]==2 && col[v]==1) cout<<0;
         else cout<<1;
      }
   }
   
   return 0;
}
 
