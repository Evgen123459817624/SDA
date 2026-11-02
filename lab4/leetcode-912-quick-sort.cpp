class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }

private:
    void quickSort(vector<int>& nums, int left, int right) {
        if (left >= right) {
            return;
        }

        int pivot = nums[left + rand() % (right - left + 1)];

        int lt = left;
        int i = left;
        int gt = right;

        while (i <= gt) {
            if (nums[i] < pivot) {
                swap(nums[lt], nums[i]);
                lt++;
                i++;
            } else if (nums[i] > pivot) {
                swap(nums[i], nums[gt]);
                gt--;

            } else {
                i++;
            }
        }

        quickSort(nums, left, lt - 1);
        quickSort(nums, gt + 1, right);
    }
};