class Solution {
public:
    long long maximumHappinessSum(vector<int>& happ, int k) {

        sort(happ.begin() , happ.end());

        int times = 0;

        int n = happ.size();
        int index = n-1;
        long long sum = 0;

        for(int i = 1 ; i <= k ; i++)
        {
            int curr_val = happ[index] - times;

            if(curr_val <= 0)
            {
                break;
            }
            else
            {
                sum += curr_val;
            }

            index--;
            times++;
        }

        return sum;
    }
};