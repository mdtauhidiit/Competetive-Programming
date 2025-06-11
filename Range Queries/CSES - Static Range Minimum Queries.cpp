#include <bits/stdc++.h>
#define int long long
using namespace std;
 
const int N=2e5+6;
int a[N],st[N][25];
int n;
 
void PreCompute(){
   for(int i=0;i<n;i++) st[i][0]=a[i];
   for(int k=1;k<25;k++){
      for(int i=0;i<n;i++){
         if(i+(1LL<<(k-1))<n) st[i][k]=min(st[i][k-1],st[i+(1LL<<(k-1))][k-1]);
      }
   }
}
 
int getMin(int l,int r){
   int j=log2(r-l+1);
   return min(st[l][j],st[r-(1<<j)+1][j]);
}
 
int32_t main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int q; cin>>n>>q;
    for(int i=0;i<n;i++) cin>>a[i];
    PreCompute();
    while(q--){
       int l,r; cin>>l>>r;
       r--;l--;
       cout<<getMin(l,r)<<'\n';
    }
 
 return 0;
}
