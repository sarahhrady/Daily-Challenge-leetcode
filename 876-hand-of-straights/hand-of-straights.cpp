class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;

        map<int, int> count;
        for (int card : hand) {
            count[card]++;
        }

        for (auto it = count.begin(); it != count.end(); ++it) {
            if (count[it->first] > 0) {
                int start = it->first;
                int freq = count[start];
                for (int i = 0; i < groupSize; ++i) {
                    if (count[start + i] < freq) {
                        return false;
                    }
                    count[start + i] -= freq;
                }
            }
        }

        return true;
    }
};