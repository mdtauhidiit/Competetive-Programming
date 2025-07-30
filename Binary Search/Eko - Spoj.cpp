#include<bits/stdc++.h>
#define int long long
using namespace std;

bool f(vector<int> &h,int mid,int M){
   int n=h.size();
   for(auto t: h){
      M-=max(0LL,t-mid);
   }
   return M<=0;
}

int32_t main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,M; cin>>n>>M;
    vector<int> h(n);
    for(int i=0;i<n;i++) cin>>h[i];
    
    int lo=0,hi=1e9,ans=-1;
    while(lo<=hi){
       int mid=lo+(hi-lo)/2;
       if(f(h,mid,M)){
          ans=mid;
          lo=mid+1;
       }
       else hi=mid-1;
    }
    cout<<ans<<endl;
    
    return 0;
}
