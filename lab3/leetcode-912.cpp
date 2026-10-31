class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int offset = 50000;
        vector<int> count(100001, 0);

        for (int num : nums) {
            count[num + offset]++;
        }

        int k = 0;
        for (int v = 0; v < 100001; v++) {
            while (count[v] > 0) {
                nums[k] = v - offset;
                k++;
                count[v]--;
            }
        }
        return nums;
    
    }
};