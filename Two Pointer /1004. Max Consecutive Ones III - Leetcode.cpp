class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> p(n);
        for(int i=0;i<n;i++){
            if(i==0) p[i]=nums[i];
            else p[i]=p[i-1]+nums[i];
        }
        int ans=0,i=0,j=0;
        while(j<n && j>=i){
            int sum=p[j]-p[i]+nums[i];
            if(sum==j-i+1){
                ans=max(ans,j-i+1);
                j++;
            }
            else {
                int zeros=j-i+1-sum;
                if(zeros>k) i++;
                else ans=max(ans,j-i+1),j++;
            }
            if(i>j) j++;
        }
        return ans;
    }
};
