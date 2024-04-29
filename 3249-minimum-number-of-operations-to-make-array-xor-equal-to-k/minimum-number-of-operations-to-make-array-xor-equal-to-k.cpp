class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int sum = 0;
        for(int i=0; i<nums.size(); i++)
        {
            sum^=nums[i];
        }
        if(sum==k)return 0;
        vector<int>bits(31,0);
        for(int i=0; i<32; i++)
        {
            if(((sum^k)>>i)&1)
            {
               /* if(!((k>>i)&1))
                {
                int ones=0;
                for(int num:nums)
                {
                    if((num>>i)&1)ones++;
                }
                int zeros=nums.size()-ones;
                bits[i]=min(ones,zeros);
                }
                else*/
                {
                    bits[i]=1;
                }
            }
        }
        int cnt=0;
        for(int i=0; i<bits.size(); i++)
        {
            cnt+=bits[i];
        }
        return cnt;
    }
};