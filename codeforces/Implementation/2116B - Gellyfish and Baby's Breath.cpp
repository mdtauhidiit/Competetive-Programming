#include<bits/stdc++.h>
#define int long long
using namespace std;

const int m=998244353;

int Binexp(int x,int n){
   if(n==0) return 1;
   if(n%2==0) return Binexp(((x%m)*(x%m))%m,n/2);
   return ((x%m)*Binexp(((x%m)*(x%m))%m,(n-1)/2)%m)%m;
}

int Add(int a,int b){
   return (a%m+b%m)%m;
}

int32_t main(){
   
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   
   int t; cin>>t;
   while(t--){
      int n; cin>>n;
      vector<int> p(n),q(n),maxP(n),maxQ(n);
      for(int i=0;i<n;i++) {
         cin>>p[i];
         if(i==0) maxP[i]=i;
         else {
            if(p[i]>p[maxP[i-1]]) maxP[i]=i;
            else maxP[i]=maxP[i-1];
         }
      }
      for(int i=0;i<n;i++){
         cin>>q[i];
         if(i==0) maxQ[i]=i;
         else {
            if(q[i]>q[maxQ[i-1]]) maxQ[i]=i;
            else maxQ[i]=maxQ[i-1];
         }
      }
      for(int i=0;i<n;i++){
         int x=maxP[i],y=maxQ[i],ri;
         if(p[x]>q[y] || (p[x]==q[y] && q[i-x]>p[i-y])){
            ri=Add(Binexp(2LL,p[x]),Binexp(2LL,q[i-x]));
            cout<<ri<<" ";
         }
         else{
            ri=Add(Binexp(2LL,q[y]),Binexp(2LL,p[i-y]));
            cout<<ri<<" ";
         }
         
      }
      cout<<"\n";
      
   }
   
return 0;
}
 
