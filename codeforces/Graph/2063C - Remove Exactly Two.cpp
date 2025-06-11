#include <bits/stdc++.h>
#define int long long
using namespace std;

void Solve(){
    int n; cin>>n;
    vector<int> d(n+1,0);
    map<pair<int,int>,int> mp;
    for(int i=1;i<n;i++){
       int u,v; cin>>u>>v;
       mp[{u,v}]=mp[{v,u}]=1;
       d[u]++; d[v]++;
    }
    vector<vector<int>> vec;
    for(int i=1;i<=n;i++) vec.push_back({d[i],i});
    sort(vec.begin(),vec.end());
    reverse(vec.begin(),vec.end());
    int ans=0;
    for(int i=0;i<2;i++){
       for(int j=i+1;j<n;j++){
          ans=max(ans,vec[i][0]+vec[j][0]-1-mp[{vec[i][1],vec[j][1]}]);
       }
    }
    cout<<ans<<'\n';
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin>>t;
    while(t--){
       Solve();
    }

 return 0;
}
