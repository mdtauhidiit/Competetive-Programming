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
        if(rnk[p1]>rnk[p2]){
            par[p2]=p1;
            rnk[p1]+=rnk[p2];
        }
        else {
            par[p1]=p2;
            rnk[p2]+=rnk[p1];
        }
    }
};

int32_t main () {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; cin>>n;
    DSU d(n);
    vector<vector<int>> ans;
    for(int i=1;i<n;i++){
        int u,v; cin>>u>>v;
        if(d.Find(u)==d.Find(v)){
            ans.push_back({u,v});
            continue;
        }
        d.Union(u,v);
    }
    cout<<ans.size()<<'\n';
    int k=0;
    for(int i=2;i<=n;i++){
        if(d.Find(i)!=d.Find(i-1)){
            cout<<ans[k][0]<<" "<<ans[k][1]<<" "<<i<<" "<<i-1<<'\n';
            d.Union(i,i-1);
            k++;
            if(k==ans.size()) break;
        }
    }

  return 0;
}
