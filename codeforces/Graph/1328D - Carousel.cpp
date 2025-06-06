#include<bits/stdc++.h>
#define int long long
using namespace std;

void dfs(int u,int x,vector<int> &col,vector<vector<int>> &adj){
   col[u]=x;
   for(auto v: adj[u]){
      if(col[v]==0){
         dfs(v,3-x,col,adj);
      }
      else if(col[v]==col[u]){
         col[v]=3;
      }
   }
}

int32_t main(){
   
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   
   int t; cin>>t;
   while(t--){
      int n; cin>>n;
      vector<int> a(n+1),col(n+1,0);
      for(int i=1;i<=n;i++) cin>>a[i];
      vector<vector<int>> adj(n+1);
      for(int i=1;i<n;i++) {
         if(a[i]!=a[i+1]){
            adj[i].push_back(i+1);
            adj[i+1].push_back(i);
         }
      }
      if(a[1]!=a[n]){
         adj[1].push_back(n);
         adj[n].push_back(1);
      }
      for(int i=1;i<=n;i++){
         if(col[i]==0){
            dfs(i,1,col,adj);
         }
      }
      int mx=*max_element(col.begin(),col.end());
      cout<<mx<<"\n";
      for(int i=1;i<=n;i++) cout<<col[i]<<" ";
      cout<<'\n';
      
   }
   
return 0;
}

