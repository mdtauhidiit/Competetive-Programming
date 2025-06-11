#include <bits/stdc++.h>
#define int long long
using namespace std;

int a[15],b[15],c[15],d[15];
int n,m,c0,d0;
int dp[15][1005];

int f(int i,int left){
    if(left<=0) return 0;
    if(i==m+1){
        if(left>0) return (left/c0)*d0;
    }
    if(dp[i][left]!=-1) return dp[i][left];
    int k=min(a[i]/b[i],left/c[i]);
    int ans=0;
    for(int j=0;j<=k;j++){
        ans=max(ans,f(i+1,left-c[i]*j)+d[i]*j);
    }
    return dp[i][left]=ans;
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(dp,-1,sizeof(dp));
    cin>>n>>m>>c0>>d0;
    for(int i=1;i<=m;i++){
        cin>>a[i]>>b[i]>>c[i]>>d[i];
    }
    cout<<f(1,n);

 return 0;
}
