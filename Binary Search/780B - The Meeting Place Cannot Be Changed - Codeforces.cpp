#include<bits/stdc++.h>
#define int long long
using namespace std;

bool Good(long double mid,vector<int> &x,vector<int> &v){
   long double lMax=-1e9,rMin=1e9;
   int n=x.size();
   for(int i=0;i<n;i++){
      long double l=x[i]-mid*v[i];
      long double r=x[i]+mid*v[i];
      lMax=max(lMax,l);
      rMin=min(rMin,r);
   }
   return rMin>lMax;
}

int32_t main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n; cin>>n;
    vector<int> x(n),v(n);
    for(int i=0;i<n;i++) cin>>x[i];
    for(int i=0;i<n;i++) cin>>v[i];
    long double lo=0,hi=1e9,ans=0,eps=1e-9;
    while(hi-lo>eps){
       long double mid=(lo+hi)/2;
       if(Good(mid,x,v)){
          ans=mid;
          hi=mid;
       }
       else lo=mid;
    }
    cout<<fixed<<setprecision(9)<<ans<<endl;
    
    return 0;
}
