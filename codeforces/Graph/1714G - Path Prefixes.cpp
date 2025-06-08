#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=200005;
int depth[N],dp[N][2];
int par[N][25];
map<vector<int>,int> f,g;

void Dfs(int u,int p,vector<vector<int>> &Adj){
    depth[u]=depth[p]+1;
    dp[u][0]=dp[p][0]+f[{p,u}];
    dp[u][1]=dp[p][1]+g[{p,u}];
    par[u][0]=p;
    for(int i=1;i<=24;i++){
       par[u][i]=par[par[u][i-1]][i-1];
    }
    for(auto v: Adj[u]){
        if(v!=p){
            Dfs(v,u,Adj);
        }
    }
}

int FindKth(int p,int k){
    for(int i=0;i<=24;i++){
        if((1<<i)&k){
            p=par[p][i];
        }
    }
    return p;
}

void Init(){
   f.clear(); g.clear();
   memset(par,0,sizeof(par));
   memset(dp,0,sizeof(dp));
   memset(depth,0,sizeof(depth));
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int m=n-1,j=1;
        vector<vector<int>> Adj(n+1);
        while(m--){
            int pi,ai,bi; cin>>pi>>ai>>bi;
            j++;
            Adj[pi].push_back(j);
            f[{pi,j}]=ai;
            g[{pi,j}]=bi;
        }
        Dfs(1,0,Adj);
        for(int i=2;i<=n;i++){
            int l=0,r=depth[i]+1,ans;
            while(l<=r){
                int mid=(l+r)/2;
                int p=FindKth(i,mid);
                if(dp[p][1]<=dp[i][0]){
                    ans=depth[i]-mid;
                    r=mid-1;
                }
                else l=mid+1;
            }
            cout<<ans-1<<" ";
        }
        cout<<'\n';
    }

 return 0;
}
