class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq; // Stores indices of elements
        
        for (int i = 0; i < nums.size(); i++) {
            // 1. Remove indices that are out of the current window boundary
            if (!dq.empty() && dq.front() == i - k) {
                dq.pop_front();
            }
            
            // 2. Remove elements from the back that are smaller than the current element
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            
            // 3. Add the current element's index to the back
            dq.push_back(i);
            
            // 4. The first window becomes complete at index k - 1
            if (i >= k - 1) {
                ans.push_back(nums[dq.front()]);
            }
        }
        
        return ans;
    }
};
