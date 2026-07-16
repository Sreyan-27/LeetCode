class Solution {
public:
    int gcd(int x,int y){
        return y==0?x:gcd(y,x%y);
    }
    long long gcdSum(vector<int>& nums) {
        int mx=INT_MIN;
        vector<int> prefixGCd;
        for(int i:nums){
               mx=max(i,mx);
               prefixGCd.push_back(gcd(i,mx));
        }
        sort(prefixGCd.begin(),prefixGCd.end());
        int l=0;
        int r=prefixGCd.size()-1;
        long long sum=0;
        while(r>l){
           sum=sum+gcd(prefixGCd[l],prefixGCd[r]);
           l++;
           r--;
        }
        return sum;
    }
};