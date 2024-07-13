#include <bits/stdc++.h>
#define int long long
using namespace std;

class Node{
public:
   int open,close,full;
};

class SegmentTree{
public:
   vector<Node> seg;
   vector<char> a;
   int n;
   
   SegmentTree(vector<char> &arr){
      a=arr;
      n=arr.size();
      seg.resize(4*n+1);
   } 
   
   Node f(Node n1,Node n2){
      Node ans;
      ans.full=n1.full+n2.full+min(n1.open,n2.close);
      ans.open=n1.open+n2.open-min(n1.open,n2.close);
      ans.close=n1.close+n2.close-min(n1.open,n2.close);
      return ans;
   }
   
   Node create(char c){
      Node ans;
      if(c=='(') ans={1,0,0};
      else ans={0,1,0};
      return ans;
   }
   
   void Build(int id,int l,int r){
      if(r-l==1){
         seg[id]=create(a[l]);
         return ;
      }
      int mid=l+(r-l)/2;
      Build(2*id,l,mid);
      Build(2*id+1,mid,r);
      seg[id]=f(seg[2*id],seg[2*id+1]);
   }
   
   Node Query(int x,int y,int id,int l,int r){
      if(y<=l || x>=r) return {0,0,0};
      if(l>=x && r<=y) return seg[id];
      int mid=l+(r-l)/2;
      return f(Query(x,y,2*id,l,mid),Query(x,y,2*id+1,mid,r));
   }
};

int32_t main() {
   
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   
   string s; cin>>s;
   int q; cin>>q;
   int n=s.size();
   vector<char> a;
   for(auto i: s) a.push_back(i);
   SegmentTree tree(a);
   tree.Build(1,0,n);
   while(q--){
      int l,r; cin>>l>>r;
      l--;
      cout<<tree.Query(l,r,1,0,n).full*2<<'\n';
   }
   
   
   return 0;
}

