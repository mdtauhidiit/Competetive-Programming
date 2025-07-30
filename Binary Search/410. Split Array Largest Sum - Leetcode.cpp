class Solution {
public:
    
    bool Good(int mid,int k,vector<int> &a){
        int n=a.size(),currSum=0,parts=1;
        for(int i=0;i<n;i++){
            if(currSum+a[i]>mid){
                currSum=a[i];
                parts++;
            }
            else currSum+=a[i];
        }
        return parts<=k;
    }
    int splitArray(vector<int>& a, int k) {
        int mx=0,sum=0;
        for(auto i: a) mx=max(mx,i),sum+=i;
        int lo=mx,hi=sum,ans=lo;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(Good(mid,k,a)){
                ans=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return ans;
    }
};
