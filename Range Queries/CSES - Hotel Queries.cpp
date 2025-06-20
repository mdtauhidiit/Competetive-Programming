#include<bits/stdc++.h>
#define int long long
using namespace std;

vector<int> a,seg;
int n,inf=1e18;

void Build(int id=1,int l=0,int r=n){
   if(r-l==1) {
      seg[id]=a[l];
      return;
   }
   int mid=(l+r)/2;
   Build(2*id,l,mid);
   Build(2*id+1,mid,r);
   seg[id]=max(seg[2*id],seg[2*id+1]);
}

int Query(int x,int y,int id=1,int l=0,int r=n){
   if(l>=y || r<=x) return 0;
   if(l>=x && r<=y) return seg[id];
   int mid=(l+r)/2;
   return max(Query(x,y,2*id,l,mid),Query(x,y,2*id+1,mid,r));
}

void Modify(int pos,int val,int id=1,int l=0,int r=n){
   if(r-l==1){
      a[pos]=val;
      seg[id]=val;
      return ;
   }
   int mid=(l+r)/2;
   if(pos<mid) Modify(pos,val,2*id,l,mid);
   else Modify(pos,val,2*id+1,mid,r);
   seg[id]=max(seg[2*id],seg[2*id+1]);
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
      int qi; cin>>qi;
      int l=0,r=n,ans=-1;
      while(l<=r){
         int mid=(l+r)/2;
         if(Query(0,mid)>=qi){
            ans=mid;
            r=mid-1;
         }
         else l=mid+1;
      }
      if(ans!=-1)Modify(ans-1,a[ans-1]-qi); 
      if(ans==-1) ans+=1;
      cout<<ans<<" ";
   }
   
return 0;
}

