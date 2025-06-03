#include<bits/stdc++.h>
using namespace std;

map<pair<int,int>,int>mp;

void dfs(int u,int x,vector<vector<int>> &adj,vector<int> &vis){
   vis[u]=1;
   for(auto v: adj[u]){
      if(!vis[v]){
         mp[{min(u,v),max(u,v)}]=x;
         dfs(v,5-x,adj,vis);
      }
   }
}

int main(){
   
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   
   int t; cin>>t;
   while(t--){
      int n; cin>>n;
      vector<vector<int>> Adj(n+1),Edges;
      vector<int> Deg(n+1,0),vis(n+1,0);
      int m=n-1,ok=1;
      while(m--){
         int u,v; cin>>u>>v;
         Edges.push_back({u,v});
         Adj[u].push_back(v);
         Adj[v].push_back(u);
         Deg[u]++; Deg[v]++;
         if(Deg[u]>2 || Deg[v]>2) ok=0;
      }
      if(!ok) cout<<"-1\n";
      else{
         int leaf=1;
         for(int i=1;i<=n;i++){
            if(Deg[i]==1) leaf=i;
         }
         dfs(leaf,2,Adj,vis);
         for(auto e: Edges){
            int u=e[0],v=e[1];
            cout<<mp[{min(u,v),max(u,v)}]<<" ";
         }
         cout<<'\n';
         mp.clear();
      }
   }
   
return 0;
}

