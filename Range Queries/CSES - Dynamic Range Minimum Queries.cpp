#include<bits/stdc++.h>
#define int long long
using namespace std;
 
vector<int> a,seg;
int n,inf=1e18;
 
void Build(int id=1,int l=0,int r=n){
   if(r-l==1){
      seg[id]=a[l];
      return ;
   }
   int mid=(l+r)/2;
   Build(2*id,l,mid);
   Build(2*id+1,mid,r);
   seg[id]=min(seg[2*id],seg[2*id+1]);
}
 
int Query(int x,int y,int id=1,int l=0,int r=n){
   if(l>=y || r<=x) return inf;
   if(l>=x && r<=y) return seg[id];
   int mid=(l+r)/2;
   return min(Query(x,y,2*id,l,mid),Query(x,y,2*id+1,mid,r));
}
 
void Update(int pos,int val,int id=1,int l=0,int r=n){
   if(r-l==1){
      a[pos]=val;
      seg[id]=val;
      return;
   }
   int mid=(l+r)/2;
   if(pos<mid) 
       Update(pos,val,2*id,l,mid);
   else 
       Update(pos,val,2*id+1,mid,r);
   seg[id]=min(seg[2*id],seg[2*id+1]);
}
 
int32_t main(){
   
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   
   int q; cin>>n>>q;
   a.resize(n);
   seg.resize(4*n+1);
   for(int i=0;i<n;i++) cin>>a[i];
   Build();
   while(q--){
      int t; cin>>t;
      if(t==1){
         int k,u; cin>>k>>u;
         Update(k-1,u);
      }
      else {
         int a,b; cin>>a>>b;
         cout<<Query(a-1,b)<<'\n';
      }
   }
   
return 0;
}
