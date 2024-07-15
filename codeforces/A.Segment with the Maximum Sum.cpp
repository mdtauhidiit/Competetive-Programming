#include <bits/stdc++.h>
#define int long long
using namespace std;
 
class SegmentTree{
public:

    struct Node{
       int pre,suf,sum,best;
       Node(int val){
         sum=val;
         pre=suf=best=max(0LL,val);
      }
    };
    
    vector<Node> seg;
    vector<int> a;
    int n;
    
    SegmentTree(vector<int> &Arr){
       n=Arr.size();
       a=Arr;
       seg.resize(4*n+1,Node(0));
    }
    
    Node f(Node l,Node r){
       Node ans(0);
       ans.sum=l.sum+r.sum;
       ans.pre=max(l.sum+r.pre,l.pre);
       ans.suf=max(r.sum+l.suf,r.suf);
       ans.best=max({l.best,r.best,l.suf+r.pre});
       return ans;
    }
    
    void Build(int id,int l,int r){
       if(r-l==1){
          Node new_node(a[l]);
          seg[id] = new_node;
          return ;
       }
       int mid=(l+r)/2;
       Build(2*id,l,mid);
       Build(2*id+1,mid,r);
       seg[id]=f(seg[2*id],seg[2*id+1]);
    }
    
    void Modify(int pos,int val,int id,int l,int r){
       if(r-l==1){
          a[pos]=val;
          Node new_node(val);
          seg[id] = new_node;
          return ;
       }
       int mid=(l+r)/2;
       if(pos<mid) Modify(pos,val,2*id,l,mid);
       else Modify(pos,val,2*id+1,mid,r);
       seg[id]=f(seg[2*id],seg[2*id+1]);
    }
    
    int CurrAns(){
       return seg[1].best;
    }
    
};
 
int32_t main() {
   
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
   
    int n,q; cin>>n>>q;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    SegmentTree st(a);
    st.Build(1,0,n);
    cout<<st.CurrAns()<<'\n';
    while(q--){
       int i,v; cin>>i>>v;
       st.Modify(i-1,v,1,0,n);
       cout<<st.CurrAns()<<'\n';
    } 
 
    return 0;
 
}
