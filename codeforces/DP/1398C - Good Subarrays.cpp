#include<bits/stdc++.h>
#define int long long
using namespace std;

/*
Intuition - > Good def : P[j]-P[i] = j-i
              where P[i] = prefix sum till index i
              Now  , P[j] - P[i] = j-i
                     P[j] - j = P[i]-i;
*/

int32_t main(){
   
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   
   int t; cin>>t;
   while(t--){
      int n; cin>>n;
      vector<int> a(n+1),p(n+1,0);
      for(int i=1;i<=n;i++) {
         char c; cin>>c;
         a[i]=c-'0';
      }
      for(int i=1;i<=n;i++){
         p[i]=p[i-1]+a[i];
      }
      map<int,int> f;
      f[0]=1;
      int ans=0;
      for(int i=1;i<=n;i++){
         int x=p[i]-i;
         ans+=f[x];
         f[x]++;
      }
      cout<<ans<<endl;
   }
   
return 0;
}

