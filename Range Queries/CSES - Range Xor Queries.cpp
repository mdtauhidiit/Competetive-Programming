#include<bits/stdc++.h>
#define int long long
using namespace std;
 
int32_t main(){
   
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   
   int n,q; cin>>n>>q;
   vector<int> a(n+1),xors(n+1,0);
   for(int i=1;i<=n;i++){
      int x; cin>>x;
      a[i]=x;
      xors[i]=xors[i-1]^x;
   }
   while(q--){
      int a,b; cin>>a>>b;
      int ans=xors[b]^xors[a-1];
      cout<<ans<<'\n';
   }
   
   return 0;
}
 
 
