#include<bits/stdc++.h>
#define int long long
using namespace std;

bool f(int mid,int C,vector<int> &x){
   int n=x.size(),pos=x[0],cow=1;
   for(int i=1;i<n;i++){
      if(x[i]-pos>=mid){
         pos=x[i];
         cow++;
      }
   }
   return cow>=C;
}

int32_t main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t; cin>>t;
    while(t--){
       int n,C; cin>>n>>C;
       vector<int> x(n);
       for(int i=0;i<n;i++) cin>>x[i];
       sort(x.begin(),x.end());
       int lo=0,hi=1e9,ans=0;
       while(lo<=hi){
          int mid=lo+(hi-lo)/2;
          if(f(mid,C,x)){
             ans=mid;
             lo=mid+1;
          }
          else hi=mid-1;
       }
       cout<<ans<<endl;
    }
    
    return 0;
}
