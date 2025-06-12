#include<bits/stdc++.h>
#define int long long
using namespace std;


int32_t main(){
   
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   
   int n,k; cin>>n>>k;
   vector<int> a(n+1),p(n+1,0);
   int cnt=0,mx=0;
   for(int i=1;i<=n;i++) {
      cin>>a[i];
      p[i]=p[i-1]+a[i];
      if(a[i]) cnt++;
      else cnt=0;
      mx=max(mx,cnt);
   }
   int i=1,j=1,idx1=0,idx2=0;
   while(j<=n && j>=i){
      int one=p[j]-p[i-1];
      int zero=j-i+1-one;
      if(zero<=k){
         if(j-i+1>mx) {
            mx=j-i+1;
            idx2=j,idx1=i;
         }
         j++;
      }
      else i++;
   }
   cout<<mx<<"\n";
   for(int i=1;i<=n;i++){
      if(i<idx1 || i>idx2) cout<<a[i]<<" ";
      else cout<<1<<" ";
   }
   
return 0;
}

