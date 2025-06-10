#include<bits/stdc++.h>
#define int long long
using namespace std;

const int inf=1e18;

class DSU {
public: 
    vector<int> par,rnk,mn;
    DSU(int n){
       par.resize(n+1);
       rnk.resize(n+1,1);
       mn.resize(n+1,inf);
       iota(par.begin(),par.end(),0);
    } 
    
    int Find(int x) {
       if(par[x]==x) return x;
       return par[x]=Find(par[x]);
    }
    
    void Union(int a,int b,int w){
       int p1=Find(a),p2=Find(b);
       if(p1==p2) return ;
       if(rnk[p1]>=rnk[p2]){
          par[p2]=p1; rnk[p1]+=rnk[p2];
          mn[p1]=min(mn[p1],mn[p2]);
          mn[p1]=min(mn[p1],w);
       }
       else {
          par[p1]=p2; rnk[p2]+=rnk[p1];
          mn[p2]=min(mn[p2],mn[p1]);
          mn[p2]=min(mn[p2],w);
       }
    }
};

int32_t main(){
   
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   
   int t; cin>>t;
   while(t--){
      int n,m; cin>>n>>m;
      DSU d(n);
      vector<vector<int>> Edges;
      while(m--){
         int u,v,w; cin>>u>>v>>w;
         Edges.push_back({w,u,v});
      }
      sort(Edges.begin(),Edges.end());
      int ans=inf;
      for(auto e: Edges){
         int u=e[1],v=e[2],w=e[0];
         if(d.Find(u)!=d.Find(v)){
            d.Union(u,v,w);
         }
         if(d.Find(1)==d.Find(n)){
            ans=min(ans,d.mn[d.Find(1)]+w);
         }
      }
      cout<<ans<<endl;
   }
   
return 0;
}

