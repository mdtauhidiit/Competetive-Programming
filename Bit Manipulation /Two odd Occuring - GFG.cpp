class Solution {
  public:
    vector<int> twoOddNum(vector<int>& arr) {
        // code here
        int x=0,n=arr.size();
        for(int i=0;i<n;i++) x^=arr[i];
        int lsb=x&(-x),a=0,b=0;
        for(int i=0;i<n;i++){
            if(lsb&arr[i]) a^=arr[i];
            else b^=arr[i];
        }
        if(a>b) return {a,b};
        else return {b,a};
    }
};
