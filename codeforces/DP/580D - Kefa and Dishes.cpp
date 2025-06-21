#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,m,k,a[20];
map<pair<int,int>,int> mp;

//f(p,mask)-> maximum satisfaction achived if previously at pth dish
//           and mask represents all the dishes ate so far now.

int f(int p,int mask,vector<vector<int>> &dp){
   int dishes=__builtin_popcountll(mask);
   if(dishes==m) return 0;
   if(dp[p][mask]!=-1) return dp[p][mask];
   int ans=0;
   for(int j=0;j<n;j++){
      int taken=(1<<j)&mask;
      if(!taken){
         int newMask=mask|(1<<j);
         ans=max(ans,f(j,newMask,dp)+a[j]+mp[{p,j}]);
      }
   }
   return dp[p][mask]=ans;
}


int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin>>n>>m>>k;
    for(int i=0;i<n;i++) cin>>a[i];
    vector<vector<int>> dp(n+1,vector<int>(1<<n,-1));
    while(k--){
       int xi,yi,ci; cin>>xi>>yi>>ci;
       xi--;yi--;
       mp[{xi,yi}]=ci;
    }
    cout<<f(n,0,dp)<<endl;

    return 0;
}
