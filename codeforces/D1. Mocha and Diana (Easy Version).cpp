#include <bits/stdc++.h>
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
        return par[x] = Find(par[x]);
    }

    void Union(int a,int b){
        int p1=Find(a),p2=Find(b);
        if(p1==p2) return;
        if(rnk[p1]>=rnk[p2]){
            par[p2]=p1;
            rnk[p1]+=rnk[p2];
        }
        else {
            par[p1]=p2;
            rnk[p2]+=rnk[p1];
        }
    }
};

int32_t main() {
   
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   
   int n,m1,m2; cin>>n>>m1>>m2;
   DSU Mocha(n),Diana(n);
   while(m1--){
      int u,v; cin>>u>>v;
      Mocha.Union(u,v);
   }
   while(m2--){
      int u,v; cin>>u>>v;
      Diana.Union(u,v);
   }
   vector<vector<int>> edges;
   for(int i=1;i<=n;i++){
      for(int j=i+1;j<=n;j++){
         if(Mocha.Find(i)==Mocha.Find(j)) continue;
         if(Diana.Find(i)==Diana.Find(j)) continue;
         Mocha.Union(i,j);
         Diana.Union(i,j);
         edges.push_back({i,j});
      }
   }
   cout<<edges.size()<<'\n';
   for(auto e: edges){
      cout<<e[0]<<" "<<e[1]<<'\n';
   }
   
   return 0;
}

