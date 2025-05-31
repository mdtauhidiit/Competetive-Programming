#include<bits/stdc++.h>
#define int long long
using namespace std;

/*
Intuition -> (a+b) = (a^b) + 2(a&b)
       Here  (a+b) = (a^b)
   Therefore (a&b) = 0
   Also , A number that is power of 2 never share any bit in common with numbers less than it 
   Ans => 2^n- max(x, y)

*/
int32_t main(){
   
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   
   int t; cin>>t;
   while(t--){
      int x,y; cin>>x>>y;
      
      int mx=max(x,y);
      int rmb=__builtin_clzll(mx);
      rmb=64-rmb;
      int ans=(1LL<<rmb)-mx;
      if(x==y) ans=-1;
      cout<<ans<<endl;
   }
   
return 0;
}
