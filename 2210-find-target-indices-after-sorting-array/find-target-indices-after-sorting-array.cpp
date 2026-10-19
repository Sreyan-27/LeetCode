class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<int> o;
        int count=0;
        for(int i:nums){
            if(i==target){
                o.push_back(count);
            }
            count++;
        }
        return o;
    }
};