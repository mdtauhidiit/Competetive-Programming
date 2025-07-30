#include<bits/stdc++.h>
#define int long long
using namespace std;

bool f(int mid,int K,vector<int> &a){
   int n=a.size(),cuts=0;
   for(int i=0;i<n;i++){
      cuts+=(a[i]/mid);
      if(a[i]%mid==0){
         cuts--;
      }
   }
   return cuts<=K;
}

int32_t main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t=1;
    while(t--){
       int n,K; cin>>n>>K;
       vector<int> a(n);
       for(int i=0;i<n;i++) cin>>a[i];
       int lo=1,hi=1e9,ans=0;
       while(lo<=hi){
          int mid=lo+(hi-lo)/2;
          if(f(mid,K,a)){
             ans=mid;
             hi=mid-1;
          }
          else lo=mid+1;
       }
       cout<<ans<<endl;
    }
    
    return 0;
}
