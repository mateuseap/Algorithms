//Question link: https://leetcode.com/problems/compute-alternating-sum/description

class Solution {
public:
    int alternatingSum(vector<int>& nums) {
        int result = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 == 0) {
                result += nums[i];
            } else {
                result -= nums[i];
            }
        }

        return result;
    }
};