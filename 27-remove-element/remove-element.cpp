class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int>nums2;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]!=val)
            {
                nums2.push_back(nums[i]);
            }
        }
        sort(nums2.begin(), nums2.end());
        nums=nums2;
        return nums.size();
    }
};