#include <bits/stdc++.h>
#define int long long
using namespace std;

class SegmentTree{
public:
   vector<int> seg,a;
   int n;
   
   SegmentTree(vector<int> &arr){
      a=arr;
      n=a.size();
      seg.resize(4*n+1);
   } 
   
   int f(int x,int y,int level){
      if(level%2) return (x|y);
      return (x^y);
   }
   
   void Build(int id,int l,int r,int level){
      if(r-l==1){
         seg[id]=a[l];
         return;
      }
      int mid=(l+r)/2;
      Build(2*id,l,mid,level-1);
      Build(2*id+1,mid,r,level-1);
      seg[id]=f(seg[2*id],seg[2*id+1],level);
   }
   
   void Modify(int pos,int val,int id,int l,int r,int level){
      if(r-l==1){
         seg[id]=val;
         a[pos]=val;
         return;
      }
      int mid=(l+r)/2;
      if(pos<mid) Modify(pos,val,2*id,l,mid,level-1);
      else Modify(pos,val,2*id+1,mid,r,level-1);
      seg[id]=f(seg[2*id],seg[2*id+1],level);
   }
};

int32_t main() {
   
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int level,m; cin>>level>>m;
    int n=(1<<level);
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    SegmentTree st(a);
    st.Build(1,0,n,level);
    while(m--){
       int pi,bi; cin>>pi>>bi;
       st.Modify(pi-1,bi,1,0,n,level);
       cout<<st.seg[1]<<endl;
    }
    return 0;

}
