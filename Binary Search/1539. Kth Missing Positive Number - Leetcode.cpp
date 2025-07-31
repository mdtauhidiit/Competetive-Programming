class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<int> p(10001,1);
        for(auto i: arr) p[i]=0;
        p[0]=0;
        for(int i=1;i<=10000;i++) p[i]+=p[i-1];
        int l=1,r=10001,ans=-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(p[mid]>=k){
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};
