class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int sum = 0;
        for(int i=0; i<nums.size(); i++)
        {
            sum^=nums[i];
        }
        if(sum==k)return 0;
        //vector<int>bits(31,0);
        int cnt=0;
        for(int i=0; i<32; i++)
        {
            if(((sum^k)>>i)&1)
            {
                cnt+=1; 
            }
        }
       
        return cnt;
    }
};