#include<bits/stdc++.h>
#define int long long
using namespace std;

class DSU{
public:
   vector<int> par,rnk;
   
   DSU(int n){
      par.resize(n+1);
      rnk.resize(n+1);
      for(int i=0;i<=n;i++){
         par[i]=i;
         rnk[i]=1;
      }
   }
   
   int Find(int x){
      if(par[x]==x) return x;
      return par[x]=Find(par[x]);
   }  
   
   void Union(int a,int b){
      int p1=Find(a),p2=Find(b);
      if(p1==p2) return ;
      if(rnk[p1]>=rnk[p2]){
         rnk[p1]+=rnk[p2];
         par[p2]=p1;
      } else {
         rnk[p2]+=rnk[p1];
         par[p1]=p2;
      }
   }
};

int32_t main(){
   
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   
   int n,q; cin>>n>>q;
   DSU d(n);
   vector<vector<int>> Edges;
   vector<int> query(q),p(q);
   for(int i=1;i<n;i++){
      int u,v,w; cin>>u>>v>>w;
      Edges.push_back({w,u,v});
   }
   for(int i=0;i<q;i++) cin>>query[i];
   p=query;
   sort(Edges.begin(),Edges.end());
   sort(query.begin(),query.end());
   map<int,int> ans;
   int i=0,j=0,prev=0,res=0;
   while(j<q){
      int wmx=query[j];
      ans[wmx]=ans[prev];
      while(i<n-1 && Edges[i][0]<=wmx){
         int u=Edges[i][1],v=Edges[i][2];
         int r1=d.rnk[d.Find(u)],r2=d.rnk[d.Find(v)];
         d.Union(u,v);
         int x=d.rnk[d.Find(u)];
         res+= (x*(x-1)/2-r1*(r1-1)/2-r2*(r2-1)/2);
         ans[wmx]=res;
         i++;
      }
      prev=wmx;
      j++;
   }
   for(int i=0;i<q;i++) cout<<ans[p[i]]<<" ";
   
return 0;
}

